#ifndef WEBDRIVERXX_BROWSERS_CHROME_H
#define WEBDRIVERXX_BROWSERS_CHROME_H

#include "../capabilities.h"
#include <list>

namespace webdriverxx {
namespace chrome {
namespace device {
	std::list<std::string> deviceList {
        "BlackBerry Z30",
        "Blackberry PlayBook",
        "Galaxy Note 3",
        "Galaxy Note II",
        "Galaxy S III",
        "Kindle Fire HDX",
		"LG Optimus L70",
		"Laptop with HiDPI screen",
		"Laptop with MDPI screen",
		"Laptop with touch",
		"Microsoft Lumia 550",
		"Microsoft Lumia 950",
		"Moto G4",
		"Nexus 10",
		"Nexus 4",
		"Nexus 5",
		"Nexus 5X",
		"Nexus 6",
		"Nexus 6P",
		"Nexus 7",
		"Nokia Lumia 520",
		"Nokia N9",
		"iPad Mini",
		"iPhone 4",
		"JioPhone 2",
		"Galaxy S5",
		"Pixel 2",
		"Pixel 2 XL",
		"iPhone 5/SE",
		"iPhone 6/7/8",
		"iPhone 6/7/8 Plus",
		"iPhone X",
		"iPad",
		"iPad Pro",
		"Surface Duo",
		"Galaxy Fold"
    };
	
	struct deviceMetrics : JsonObject {
		WEBDRIVERXX_PROPERTIES_BEGIN(deviceMetrics)
		WEBDRIVERXX_PROPERTY(width, "width", int)
		WEBDRIVERXX_PROPERTY(height, "height", int)
		WEBDRIVERXX_PROPERTY(pixelRatio, "pixelRatio", float)
		WEBDRIVERXX_PROPERTY(touch, "touch", bool)
		WEBDRIVERXX_PROPERTIES_END()
	};
}

struct MobileEmulation : JsonObject {
	WEBDRIVERXX_PROPERTIES_BEGIN(MobileEmulation)
	WEBDRIVERXX_PROPERTY(deviceName, "deviceName", std::string)
	WEBDRIVERXX_PROPERTY(userAgent, "userAgent", std::string)
	WEBDRIVERXX_PROPERTY(deviceMetrics, "deviceMetrics", device::deviceMetrics)
	WEBDRIVERXX_PROPERTIES_END()
};

struct PerfLoggingPrefs : JsonObject {
	WEBDRIVERXX_PROPERTIES_BEGIN(PerfLoggingPrefs)
	WEBDRIVERXX_PROPERTY(EnableNetwork, "enableNetwork", bool)
	WEBDRIVERXX_PROPERTY(enablePage, "enablePage", bool)
	WEBDRIVERXX_PROPERTY(enableTimeline, "enableTimeline", bool)
	WEBDRIVERXX_PROPERTY(tracingCategories, "tracingCategories", std::string)
	WEBDRIVERXX_PROPERTY(bufferUsageReportingInterval, "bufferUsageReportingInterval", int)
	WEBDRIVERXX_PROPERTIES_END()
};

} // namespace chrome

struct Chrome : Capabilities { // copyable
	Chrome(const Capabilities& defaults = Capabilities())
		: Capabilities(defaults) {
		SetBrowserName(browser::Chrome);
		SetVersion("");
		SetPlatform(platform::Any);
	}

	// See https://sites.google.com/a/chromium.org/chromedriver/capabilities for details
	WEBDRIVERXX_PROPERTIES_BEGIN(Chrome)
	WEBDRIVERXX_PROPERTY(LoggingPrefs, "loggingPrefs", LoggingPrefs)
	WEBDRIVERXX_PROPERTY(Args, "args", std::vector<std::string>)
	WEBDRIVERXX_PROPERTY(Binary, "binary", std::string)
	// Each extension is a base64-encoded .crx file
	WEBDRIVERXX_PROPERTY(Extensions, "extensions", std::vector<std::string>)
	WEBDRIVERXX_PROPERTY(LocalState, "localState", JsonObject)
	WEBDRIVERXX_PROPERTY(Prefs, "prefs", JsonObject)
	WEBDRIVERXX_PROPERTY(Detach, "detach", bool)
	WEBDRIVERXX_PROPERTY(DebuggerAddress, "debuggerAddress", std::string)
	WEBDRIVERXX_PROPERTY(ExcludeSwitches, "excludeSwitches", std::vector<std::string>)
	WEBDRIVERXX_PROPERTY(MinidumpPath, "minidumpPath", std::string)
	WEBDRIVERXX_PROPERTY(MobileEmulation, "mobileEmulation", chrome::MobileEmulation)
	WEBDRIVERXX_PROPERTY(PerfLoggingPrefs, "perfLoggingPrefs", chrome::PerfLoggingPrefs)
	WEBDRIVERXX_PROPERTIES_END()
};

} // namespace webdriverxx

#endif
