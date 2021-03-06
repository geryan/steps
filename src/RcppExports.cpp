// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// shuffle_vec
IntegerVector shuffle_vec(int min, int max);
RcppExport SEXP _steps_shuffle_vec(SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type min(minSEXP);
    Rcpp::traits::input_parameter< int >::type max(maxSEXP);
    rcpp_result_gen = Rcpp::wrap(shuffle_vec(min, max));
    return rcpp_result_gen;
END_RCPP
}
// barrier_to_dispersal
bool barrier_to_dispersal(int source_x, int source_y, int sink_x, int sink_y, NumericMatrix barriers_map);
RcppExport SEXP _steps_barrier_to_dispersal(SEXP source_xSEXP, SEXP source_ySEXP, SEXP sink_xSEXP, SEXP sink_ySEXP, SEXP barriers_mapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type source_x(source_xSEXP);
    Rcpp::traits::input_parameter< int >::type source_y(source_ySEXP);
    Rcpp::traits::input_parameter< int >::type sink_x(sink_xSEXP);
    Rcpp::traits::input_parameter< int >::type sink_y(sink_ySEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type barriers_map(barriers_mapSEXP);
    rcpp_result_gen = Rcpp::wrap(barrier_to_dispersal(source_x, source_y, sink_x, sink_y, barriers_map));
    return rcpp_result_gen;
END_RCPP
}
// can_source_cell_disperse
IntegerVector can_source_cell_disperse(int source_x, int source_y, NumericMatrix iterative_population_state, NumericMatrix future_population_state, NumericMatrix carrying_capacity_available, NumericMatrix habitat_suitability_map, NumericMatrix barriers_map, int dispersal_distance, NumericVector dispersal_kernel);
RcppExport SEXP _steps_can_source_cell_disperse(SEXP source_xSEXP, SEXP source_ySEXP, SEXP iterative_population_stateSEXP, SEXP future_population_stateSEXP, SEXP carrying_capacity_availableSEXP, SEXP habitat_suitability_mapSEXP, SEXP barriers_mapSEXP, SEXP dispersal_distanceSEXP, SEXP dispersal_kernelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type source_x(source_xSEXP);
    Rcpp::traits::input_parameter< int >::type source_y(source_ySEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type iterative_population_state(iterative_population_stateSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type future_population_state(future_population_stateSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type carrying_capacity_available(carrying_capacity_availableSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type habitat_suitability_map(habitat_suitability_mapSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type barriers_map(barriers_mapSEXP);
    Rcpp::traits::input_parameter< int >::type dispersal_distance(dispersal_distanceSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type dispersal_kernel(dispersal_kernelSEXP);
    rcpp_result_gen = Rcpp::wrap(can_source_cell_disperse(source_x, source_y, iterative_population_state, future_population_state, carrying_capacity_available, habitat_suitability_map, barriers_map, dispersal_distance, dispersal_kernel));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_dispersal
NumericMatrix rcpp_dispersal(NumericMatrix starting_population_state, NumericMatrix potential_carrying_capacity, NumericMatrix habitat_suitability_map, NumericMatrix barriers_map, int dispersal_steps, int dispersal_distance, NumericVector dispersal_kernel, double dispersal_proportion);
RcppExport SEXP _steps_rcpp_dispersal(SEXP starting_population_stateSEXP, SEXP potential_carrying_capacitySEXP, SEXP habitat_suitability_mapSEXP, SEXP barriers_mapSEXP, SEXP dispersal_stepsSEXP, SEXP dispersal_distanceSEXP, SEXP dispersal_kernelSEXP, SEXP dispersal_proportionSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type starting_population_state(starting_population_stateSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type potential_carrying_capacity(potential_carrying_capacitySEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type habitat_suitability_map(habitat_suitability_mapSEXP);
    Rcpp::traits::input_parameter< NumericMatrix >::type barriers_map(barriers_mapSEXP);
    Rcpp::traits::input_parameter< int >::type dispersal_steps(dispersal_stepsSEXP);
    Rcpp::traits::input_parameter< int >::type dispersal_distance(dispersal_distanceSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type dispersal_kernel(dispersal_kernelSEXP);
    Rcpp::traits::input_parameter< double >::type dispersal_proportion(dispersal_proportionSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_dispersal(starting_population_state, potential_carrying_capacity, habitat_suitability_map, barriers_map, dispersal_steps, dispersal_distance, dispersal_kernel, dispersal_proportion));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_steps_shuffle_vec", (DL_FUNC) &_steps_shuffle_vec, 2},
    {"_steps_barrier_to_dispersal", (DL_FUNC) &_steps_barrier_to_dispersal, 5},
    {"_steps_can_source_cell_disperse", (DL_FUNC) &_steps_can_source_cell_disperse, 9},
    {"_steps_rcpp_dispersal", (DL_FUNC) &_steps_rcpp_dispersal, 8},
    {NULL, NULL, 0}
};

RcppExport void R_init_steps(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
