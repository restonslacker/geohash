#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP _geohash_gh_decode(SEXP);
extern SEXP _geohash_gh_encode(SEXP, SEXP, SEXP);
extern SEXP _geohash_gh_neighbour(SEXP, SEXP);
extern SEXP _geohash_gh_neighbours(SEXP);
extern SEXP _geohash_RcppExport_registerCCallable();

static const R_CallMethodDef CallEntries[] = {
    {"_geohash_gh_decode",                    (DL_FUNC) &_geohash_gh_decode,                    1},
    {"_geohash_gh_encode",                    (DL_FUNC) &_geohash_gh_encode,                    3},
    {"_geohash_gh_neighbour",                 (DL_FUNC) &_geohash_gh_neighbour,                 2},
    {"_geohash_gh_neighbours",                (DL_FUNC) &_geohash_gh_neighbours,                1},
    {"_geohash_RcppExport_registerCCallable", (DL_FUNC) &_geohash_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

void R_init_geohash(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
