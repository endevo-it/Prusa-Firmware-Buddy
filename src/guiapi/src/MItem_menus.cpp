#include "MItem_menus.hpp"
#include "screen_menus.hpp"
#include "ScreenHandler.hpp"
#include "screen_sysinf.hpp"
#include "screen_qr_error.hpp"
#include "screen_test.hpp"
#include "screen_messages.hpp"
#include "marlin_client.h"
#include "translation_provider_FILE.hpp"
#include "filament_sensor.hpp"
#include "translator.hpp"

/*****************************************************************************/
//MI_VERSION_INFO
MI_VERSION_INFO::MI_VERSION_INFO()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_VERSION_INFO::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuVersionInfo);
}

/*****************************************************************************/
//MI_SENSOR_INFO
MI_SENSOR_INFO::MI_SENSOR_INFO()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_SENSOR_INFO::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuSensorInfo);
}

/*****************************************************************************/
MI_ODOMETER::MI_ODOMETER()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_ODOMETER::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuOdometer);
}

/*****************************************************************************/
//MI_FILAMENT
MI_FILAMENT::MI_FILAMENT()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_FILAMENT::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuFilament);
}

/*****************************************************************************/
//MI_SYS_INFO
MI_SYS_INFO::MI_SYS_INFO()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_SYS_INFO::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(ScreenFactory::Screen<screen_sysinfo_data_t>);
}

/*****************************************************************************/
//MI_STATISTIC_disabled
MI_STATISTIC_disabled::MI_STATISTIC_disabled()
    : WI_LABEL_t(_(label), 0, is_enabled_t::no, is_hidden_t::no) {
}

/*****************************************************************************/
//MI_FAIL_STAT_disabled
MI_FAIL_STAT_disabled::MI_FAIL_STAT_disabled()
    : WI_LABEL_t(_(label), 0, is_enabled_t::no, is_hidden_t::no) {
}

/*****************************************************************************/
//MI_SUPPORT_disabled
MI_SUPPORT_disabled::MI_SUPPORT_disabled()
    : WI_LABEL_t(_(label), 0, is_enabled_t::no, is_hidden_t::no) {
}

/*****************************************************************************/
//MI_TEMPERATURE
MI_TEMPERATURE::MI_TEMPERATURE()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_TEMPERATURE::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuTemperature);
}

/*****************************************************************************/
//MI_MOVE_AXIS
MI_MOVE_AXIS::MI_MOVE_AXIS()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_MOVE_AXIS::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuMove);
}

/*****************************************************************************/
//MI_SERVICE
MI_SERVICE::MI_SERVICE()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_SERVICE::click(IWindowMenu & /*window_menu*/) {
    //screen_open(get_scr_menu_service()->id);
}

/*****************************************************************************/
//MI_TEST
MI_TEST::MI_TEST()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_TEST::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(ScreenFactory::Screen<screen_test_data_t>);
}

/*****************************************************************************/
//MI_FW_UPDATE
MI_FW_UPDATE::MI_FW_UPDATE()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_FW_UPDATE::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuFwUpdate);
}

/*****************************************************************************/
//MI_ESp_UPDATE
MI_ESP_UPDATE::MI_ESP_UPDATE()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_ESP_UPDATE::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuESPUpdate);
}

/*****************************************************************************/
//MI_LAN_SETTINGS
MI_LAN_SETTINGS::MI_LAN_SETTINGS()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_LAN_SETTINGS::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuLanSettings);
}

/*****************************************************************************/
//MI_MESSAGES
MI_MESSAGES::MI_MESSAGES()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_MESSAGES::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(ScreenFactory::Screen<screen_messages_data_t>);
}

/*****************************************************************************/
//MI_LANGUAGE
MI_LANGUAGE::MI_LANGUAGE()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_LANGUAGE::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuLanguages);
}

/*****************************************************************************/
//MI_HW_SETUP
MI_HW_SETUP::MI_HW_SETUP()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_HW_SETUP::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuHwSetup);
}

/*****************************************************************************/
//MI_CURRENT_PROFILE
MI_CURRENT_PROFILE::MI_CURRENT_PROFILE()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::yes) {
}

void MI_CURRENT_PROFILE::click(IWindowMenu & /*window_menu*/) {
    sheet_next_calibrated();
    UpdateLabel();
    marlin_set_z_offset(variant8_get_flt(eeprom_get_var(EEVAR_ZOFFSET)));
}

void MI_CURRENT_PROFILE::UpdateLabel() {
    name[0] = '[';
    uint32_t cnt = sheet_active_name(name + 1, MAX_SHEET_NAME_LENGTH);
    name[cnt + 1] = ']';
    name[cnt + 2] = 0;
    // string_view_utf8::MakeRAM is safe. "name" is member var, exists until MI_CURRENT_PROFILE is destroyed
    SetLabel(string_view_utf8::MakeRAM((const uint8_t *)name));
}

/*****************************************************************************/
//MI_EEPROM
MI_EEPROM::MI_EEPROM()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_EEPROM::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenEeprom);
}

/*****************************************************************************/
//MI_DEVHASH_IN_QR
MI_DEVHASH_IN_QR::MI_DEVHASH_IN_QR()
    : WI_SWITCH_OFF_ON_t(variant8_get_ui8(eeprom_get_var(EEVAR_DEVHASH_IN_QR)), _(label), 0, is_enabled_t::yes, is_hidden_t::no) {}
void MI_DEVHASH_IN_QR::OnChange(size_t old_index) {
    if (!old_index) {
        /// enable
        eeprom_set_var(EEVAR_DEVHASH_IN_QR, variant8_ui8(1));
    } else {
        /// disable
        eeprom_set_var(EEVAR_DEVHASH_IN_QR, variant8_ui8(0));
    }
}

/*****************************************************************************/
//MI_FOOTER_SETTINGS
MI_FOOTER_SETTINGS::MI_FOOTER_SETTINGS()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_FOOTER_SETTINGS::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuFooterSettings);
}

MI_LANGUAGUE_USB::MI_LANGUAGUE_USB()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {}

void MI_LANGUAGUE_USB::click(IWindowMenu &windowMenu) {
    if (fileProviderUSB.EnsureFile())
        Translations::Instance().RegisterProvider(Translations::MakeLangCode("ts"), &fileProviderUSB);
}

MI_LOAD_LANG::MI_LOAD_LANG()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {}

void MI_LOAD_LANG::click(IWindowMenu &windowMenu) {
    const uint8_t buffLen = 16;

    uint8_t buff[buffLen];

    FILE *srcDir = fopen("/usb/lang/ts.mo", "rb");
    FILE *dstDir = fopen("/internal/ts.mo", "wb");
    //copy languague from usb to xflash
    if (dstDir && srcDir) {
        for (size_t readBytes = fread(buff, 1, buffLen, srcDir); readBytes != 0; readBytes = fread(buff, 1, buffLen, srcDir)) {
            fwrite(buff, 1, readBytes, dstDir);
        }
    }
    fclose(dstDir);
    fclose(srcDir);
}
MI_LANGUAGUE_XFLASH::MI_LANGUAGUE_XFLASH()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {}

void MI_LANGUAGUE_XFLASH::click(IWindowMenu &windowMenu) {
    if (fileProviderInternal.EnsureFile())
        Translations::Instance().RegisterProvider(Translations::MakeLangCode("ts"), &fileProviderInternal);
}

/**********************************************************************************************/
//MI_FILAMENT_SENSOR
void MI_FILAMENT_SENSOR::no_sensor_msg() const {
    MsgBoxQuestion(_("No filament sensor detected. Verify that the sensor is connected and try again."));
}

bool MI_FILAMENT_SENSOR::init_index() const {
    fsensor_t fs = FS_instance().WaitInitialized();
    fs_not_connected = fs == fsensor_t::NotConnected;
    if (fs_not_connected) //tried to enable but there is no sensor
    {
        FS_instance().Disable();
        fs_not_connected = true;
        fs = fsensor_t::Disabled;
    }
    return fs == fsensor_t::Disabled ? 0 : 1;
}

void MI_FILAMENT_SENSOR::CheckDisconnected() {
    if (consumeNotConnected() || FS_instance().WaitInitialized() == fsensor_t::NotConnected) {
        FS_instance().Disable();
        index = 0;
        no_sensor_msg();
    }
}

bool MI_FILAMENT_SENSOR::consumeNotConnected() {
    bool ret = fs_not_connected;
    fs_not_connected = false;
    return ret;
}

void MI_FILAMENT_SENSOR::OnChange(size_t old_index) {
    old_index == 1 ? FS_instance().Disable() : FS_instance().Enable();

    fsensor_t fs = FS_instance().WaitInitialized();
    if (fs == fsensor_t::NotConnected) //tried to enable but there is no sensor
    {
        FS_instance().Disable();
        index = old_index;
        fs_not_connected = true;
    }
}

bool MI_FILAMENT_SENSOR::fs_not_connected = false;

/*****************************************************************************/
//MI_PRUSALINK
MI_PRUSALINK::MI_PRUSALINK()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_PRUSALINK::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenPrusaLink);
}

//MI_EXPERIMENTAL_SETTINGS
MI_EXPERIMENTAL_SETTINGS::MI_EXPERIMENTAL_SETTINGS()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::no) {
}

void MI_EXPERIMENTAL_SETTINGS::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuExperimentalSettings);
}

/**********************************************************************************************/
// MI_EEPROM_DIAGNOSTICS
MI_EEPROM_DIAGNOSTICS::MI_EEPROM_DIAGNOSTICS()
    : WI_LABEL_t(_(label), 0, is_enabled_t::yes, is_hidden_t::dev, expands_t::yes) {
}

void MI_EEPROM_DIAGNOSTICS::click(IWindowMenu & /*window_menu*/) {
    Screens::Access()->Open(GetScreenMenuEepromDiagnostics);
}
