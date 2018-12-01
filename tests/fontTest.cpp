#include "TestBase.h"
/// <summary>
/// Example of how to work with font
/// </summary>
class FontTest : public InfrastructureTest {
};

/// <summary>
/// Test for reseting cache
/// </summary>
TEST_F(FontTest, TestResetCache) {
	std::shared_ptr< ResetCacheRequest> request(new ResetCacheRequest);
	std::shared_ptr<AsposeResponse> actual = get_api()->resetCache(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for GetAvailableFonts resource
/// </summary>
TEST_F(FontTest, TestGetAvailableFonts) {
	std::shared_ptr<GetAvailableFontsRequest> request(new GetAvailableFontsRequest(boost::none));
	std::shared_ptr<AvailableFontsResponse> actual = get_api()->getAvailableFonts(request).get();

	ASSERT_EQ(200, actual->getCode());
}