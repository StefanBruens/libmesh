
#include "libmesh_cppunit.h"

#ifdef LIBMESH_HAVE_POLY2TRI
#  include "poly2tri/poly2tri.h"
#endif

#include <numeric>

class LibMeshPoly2TriTest : public CppUnit::TestCase {
public:
  CPPUNIT_TEST_SUITE( LibMeshPoly2TriTest );

#ifdef LIBMESH_HAVE_POLY2TRI
  CPPUNIT_TEST( testLibMeshPoly2Tri );
#endif

  CPPUNIT_TEST_SUITE_END();

private:

public:
  void setUp()
  {}

  void tearDown()
  {}

#ifdef LIBMESH_HAVE_POLY2TRI
  void testLibMeshPoly2Tri ()
  {
    std::vector<p2t::Point> pentagon {{0,0},{1,0},{1,1},{.5,1.5},{0,1}};

    std::vector<p2t::Point *> api_shim(pentagon.size());
    std::iota(api_shim.begin(), api_shim.end(), pentagon.data());

    p2t::CDT cdt(api_shim);

    cdt.Triangulate();

    auto tris = cdt.GetTriangles();

    // We mostly wanted to make sure this compiled, but might as well
    // make sure it gave us the expected triangle count while we're at
    // it.
    CPPUNIT_ASSERT_EQUAL(tris.size(), std::size_t(3));
  }
#endif
};

CPPUNIT_TEST_SUITE_REGISTRATION( LibMeshPoly2TriTest );
