as_class <- function (object, name, type = c("function", "list")) {
  type <- match.arg(type)
  stopifnot(inherits(object, type))
  class(object) <- c(name, class(object))
  invisible(object)
}

round_pop <- function (population) {
  
  population_min <- floor(population)
  
  if (steps_stash$demo_stochasticity == "full") {
    if (sum(population) == 0) return(population)
    return(rmultinom_large_int(population)[, 1])
  }
  
  if (steps_stash$demo_stochasticity == "deterministic_redistribution") {
    n <- length(population)
    k <- round(sum(population)) - sum(population_min)
    cutoff <- sort(population, partial = n - k)[n - k]
    idx <- which(population > cutoff)
    population_min[idx] <- population_min[idx] + 1
    return(population_min)
  }
  
  if (steps_stash$demo_stochasticity == "stochastic_redistribution") {
    population_extra <- population - population_min
    population_extra[] <- stats::rbinom(length(population_extra), 1, population_extra[])
    return(population_min + population_extra)
  }
  
  if (steps_stash$demo_stochasticity == "none") return(population)
  
}

get_carrying_capacity <- function (landscape, timestep) {
  
  cc <- landscape$carrying_capacity
  if (is.null(cc)) {
    
    # if there's no carrying capacity specified, return a NULL
    res <- NULL
    
  } else if (inherits(cc, "RasterLayer")) {
    
    
    # if there's a carrying capacity raster, use that
    
    # # in a future set up where lots of carrying capacity rasters could be passed in
    # if (raster::nlayers(cc) > 1) {
    #   res <- cc[[timestep]])
    # } else {
    #   res <- cc
    # }
    
    res <- cc
    
  } else if (is.function(cc)) {
    
    # if it's a function, run it on landscape
    res <- cc(landscape, timestep)
    
  } else {
    
    # otherwise, we don't support it
    stop ("invalid carrying capacity argument",
          call. = FALSE)
    
  }
  
  res
  
}

not_missing <- function (raster) {
  which(!is.na(raster::getValues(raster)))
}

warn_once <- function (condition, message, warning_name) {
  if (condition & !isTRUE(steps_stash[[warning_name]])) {
    warning(message, call. = FALSE)
    steps_stash[[warning_name]] <- TRUE
  }
}

rmultinom_large_int <- function (population) {
  
  total <- sum(population)
  
  if (total > .Machine$integer.max) {
    times <- total %/% .Machine$integer.max
    extra <- total %% .Machine$integer.max
    pop <- rep(0, length(population))
    
    for (i in seq_len(times)) {
      pop <- pop + stats::rmultinom(1, .Machine$integer.max, population)
    }
    
    pop <- pop + stats::rmultinom(1, extra, population)
    
  } else {
    
    pop <- stats::rmultinom(1, sum(population), population)
    
  }
  
  pop
  
}

bind_simulation_repetitions <- function(arglist){ # means of overcoming memory limitations to do large number of repetitions of simulation - takes list of simulation results objects from same landscape and number of timesteps and returns single combined results object
  
  if(!is.list(arglist)){stop("Please pass simulation results in a list")}
  
  for(i in 1:length(arglist)){
    if(!is.simulation_results(arglist[[i]])) stop("Arguments are not STEPS simulation results")
  }
  
  for( i in 2:length(arglist)){
    
    if(length(arglist[[1]][[1]]) != length(arglist[[i]][[1]])){
      stop("Results contain differing number of timesteps")
    }
    
    if(!all.equal(arglist[[1]][[1]][[1]]$suitability, arglist[[i]][[1]][[1]]$suitability)){
      stop("Results contain differing habitat suitability layers")
    }
  }
  
  
  sim_results <- do.call(c, arglist)
  
  class(sim_results) <- c("simulation_results", "list")
  
  return(sim_results)
  
}