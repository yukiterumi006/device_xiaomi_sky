#include <vector>
#include <string>
#include "vendor_init.h"
#include <libinit_variant.h>
#include <libinit_utils.h>

// Define fingerprint constants
#define FINGERPRINT_POCO_IN "POCO/sky_p_in/sky:14/UKQ1.231003.002/V816.0.2.0.UMWINXM:user/release-keys"
#define FINGERPRINT_REDMI_IN "Redmi/sky_in/sky:14/UKQ1.231003.002/V816.0.2.0.UMWINXM:user/release-keys"
#define FINGERPRINT_CHINA "Redmi/sky/sky:14/UKQ1.231003.002/V816.0.5.0.UMWCNXM:user/release-keys"
#define FINGERPRINT_GLOBAL_NFC "Redmi/river_global/river:14/UKQ1.231003.002/V816.0.4.0.UMWMIXM:user/release-keys"

// Define variant information structure
struct VariantInfo {
    std::string hwc_value;
    std::string boardid;
    std::string brand;
    std::string device;
    std::string marketname;
    std::string model;
    std::string mod_device;
    std::string build_fingerprint;
};

// Define variant configurations
const VariantInfo sky_poco_info = {
    "India",
    "S88019EP1",
    "POCO",
    "sky",
    "POCO M6 Pro 5G",
    "23076PC4BI",
    "sky_global",
    FINGERPRINT_POCO_IN
};

const VariantInfo sky_redmi_info = {
    "India",
    "S88018EA1",
    "Redmi",
    "sky",
    "Redmi 12 5G",
    "23076RN4BI",
    "sky_global",
    FINGERPRINT_REDMI_IN
};

const VariantInfo sky_redmi2_info = {
    "India",
    "S88019EA1",
    "Redmi",
    "sky",
    "Redmi 12 5G",
    "23076RN4BI",
    "sky_global",
    FINGERPRINT_REDMI_IN
};

const VariantInfo sky_china_info = {
    "CN",
    "S88019BA1",
    "Redmi",
    "river",
    "Redmi Note 12R",
    "23076RA4BC",
    "sky_global",
    FINGERPRINT_CHINA
};

const VariantInfo sky2_china_info = {
    "CN",
    "S88019OA1",
    "Redmi",
    "sky",
    "Redmi 12R",
    "23076RA4BC",
    "sky_global",
    FINGERPRINT_REDMI_IN
};

const VariantInfo river_info_S88029AA1 = {
    "Global",
    "S88029AA1",
    "Redmi",
    "river",
    "Redmi 12 5G",
    "23076RN8DY",
    "sky_global",
    FINGERPRINT_GLOBAL_NFC
};

const VariantInfo river_info_S88019BP1 = {
    "CN",
    "S88019BP1",
    "Redmi",
    "river",
    "Redmi 12 5G",
    "23077RABDC",
    "sky_global",
    FINGERPRINT_GLOBAL_NFC
};

const VariantInfo river_info_S88018PA1 = {
    "Global",
    "S88018PA1",
    "Redmi",
    "river",
    "Redmi 12 5G",
    "23077RABDC",
    "sky_global",
    FINGERPRINT_GLOBAL_NFC
};

const VariantInfo river_info_S88029JA1 = {
    "Japan",
    "S88029JA1",
    "Redmi",
    "river",
    "Redmi 12 5G",
    "23076RA4BR",
    "sky_global",
    FINGERPRINT_GLOBAL_NFC
};

// Define function to load properties
void vendor_load_properties() {
    // Define variants vector
    std::vector<VariantInfo> variants = {
        sky_poco_info,
        sky_redmi_info,
        sky_redmi2_info,
        sky_china_info,
        sky2_china_info,
        river_info_S88029AA1,
        river_info_S88019BP1,
        river_info_S88018PA1,
        river_info_S88029JA1
    };
    
    // Search for appropriate variant
    search_variant(variants);
    
    // Override device properties
    property_override("ro.rising.chipset", "Snapdragon 4 Gen 2");
    property_override("ro.rising.maintainer", "honokascape | cometscape");
}
