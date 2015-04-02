#include "ground_fixture.h"
#include "configuration_fixture.h"
#include "unit_test_support.h"

using namespace FullPhysics;
using namespace blitz;
BOOST_FIXTURE_TEST_SUITE(ground_breon, GroundFixture)

BOOST_AUTO_TEST_CASE(basic)
{
    BOOST_CHECK_CLOSE(breon_soil->overall_amplitude().value(), 0.1, 1e-8);
    BOOST_CHECK_CLOSE(breon_soil->asymmetry_parameter().value(), 0.3, 1e-8);
    BOOST_CHECK_CLOSE(breon_soil->geometric_factor().value(), 1.5, 1e-8);

    BOOST_CHECK_CLOSE(breon_veg->overall_amplitude().value(), 0.1, 1e-8);
    BOOST_CHECK_CLOSE(breon_veg->asymmetry_parameter().value(), 0.3, 1e-8);
    BOOST_CHECK_CLOSE(breon_veg->geometric_factor().value(), 1.5, 1e-8);

    for(int spec_idx = 0; spec_idx < 3; spec_idx++) {
        // These parameters do not vary by band number or wavenumber
        BOOST_CHECK_CLOSE(breon_veg->surface_parameter(13000, spec_idx)(0).value(), 0.1, 1e-8);
        BOOST_CHECK_CLOSE(breon_veg->surface_parameter(13000, spec_idx)(1).value(), 0.3, 1e-8);
        BOOST_CHECK_CLOSE(breon_veg->surface_parameter(13000, spec_idx)(2).value(), 1.5, 1e-8);

        BOOST_CHECK_CLOSE(breon_soil->surface_parameter(13000, spec_idx)(0).value(), 0.1, 1e-8);
        BOOST_CHECK_CLOSE(breon_soil->surface_parameter(13000, spec_idx)(1).value(), 0.3, 1e-8);
        BOOST_CHECK_CLOSE(breon_soil->surface_parameter(13000, spec_idx)(2).value(), 1.5, 1e-8);
     }

}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(ground_breon_veg_config, ConfigurationBreonVegFixture)

BOOST_AUTO_TEST_CASE(jacobian)
{
    for(int spec_idx = 0; spec_idx < 3; spec_idx++) {
        // These parameters do not vary by band number or wavenumber
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(0).value(), 0.1, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(1).value(), 0.3, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(2).value(), 1.5, 1e-8);
    }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(ground_breon_soil_config, ConfigurationBreonVegFixture)

BOOST_AUTO_TEST_CASE(jacobian)
{
    for(int spec_idx = 0; spec_idx < 3; spec_idx++) {
        // These parameters do not vary by band number or wavenumber
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(0).value(), 0.1, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(1).value(), 0.3, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(2).value(), 1.5, 1e-8);
    }
}

BOOST_AUTO_TEST_SUITE_END()
