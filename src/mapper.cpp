#include "mapper.h"

std::optional<std::string> Mapper::getError(const std::uint16_t id) const {
    const auto it = errorMap.find(id);
    if (it != errorMap.end()) {
        return it->second;
    }
    return {};
}

std::optional<std::string> Mapper::getBetriebsart(const std::uint16_t id) const {
    const auto it = betriebsartMap.find(id);
    if (it != betriebsartMap.end()) {
        return it->second;
    }
    return {};
}

std::optional<std::uint16_t> Mapper::getBetriebsartId(const std::string& betriebsart) const {
    for (const auto& element : betriebsartMap) {
        if (element.second == betriebsart) {
            return element.first;
        }
    }
    return {};
}

Type Mapper::getType(const Property property) const {
    const auto it = propertyMap.find(property);
    if (it != propertyMap.end()) {
        return it->second;
    } else {
        return Type::et_default;
    }
}

Mapper::Mapper() {
    errorMap = {{0x0002, "Schuetz klebt"},
                {0x0003, "ERR HD-SENSOR"},
                {0x0004, "Hochdruck"},
                {0x0005, "Verdampferfuehler"},
                {0x0006, "Relaistreiber"},
                {0x0007, "Relaispegel"},
                {0x0008, "Hexschalter"},
                {0x0009, "Drehzahl Luefter"},
                {0x000a, "Lueftertreiber"},
                {0x000b, "Reset Baustein"},
                {0x000c, "ND"},
                {0x000d, "ROM"},
                {0x000e, "QUELLEN MINTEMP"},
                {0x0010, "Abtauen"},
                {0x0012, "ERR T-HEI IWS"},
                {0x0017, "ERR T-FRO IWS"},
                {0x001a, "Niederdruck"},
                {0x001b, "ERR ND-DRUCK"},
                {0x001c, "ERR HD-DRUCK"},
                {0x001d, "HD-SENSOR-MAX"},
                {0x001e, "HEISSGAS-MAX"},
                {0x001f, "ERR HD-SENSOR"},
                {0x0020, "Einfrierschutz"},
                {0x0021, "KEINE LEISTUNG"}};

    betriebsartMap = {{0x0000, "Notbetrieb"},    {0x0100, "Bereitschaft"}, {0x0300, "Tagbetrieb"},
                      {0x0400, "Absenkbetrieb"}, {0x0500, "Warmwasser"},   {0x0B00, "Automatik"},
                      {0x0E00, "Handbetrieb"}};

    propertyMap = {
        {Property::kKESSELSOLLTEMP, Type::et_dec_val},
        {Property::kSPEICHERSOLLTEMP, Type::et_dec_val},
        {Property::kVORLAUFSOLLTEMP, Type::et_dec_val},
        {Property::kRAUMSOLLTEMP_I, Type::et_dec_val},
        {Property::kRAUMSOLLTEMP_II, Type::et_dec_val},
        {Property::kRAUMSOLLTEMP_III, Type::et_dec_val},
        {Property::kRAUMSOLLTEMP_NACHT, Type::et_dec_val},
        {Property::kUHRZEIT, Type::et_zeit},
        {Property::kDATUM, Type::et_datum},
        {Property::kGERAETE_ID, Type::et_dev_id},
        {Property::kAUSSENTEMP, Type::et_dec_val},
        {Property::kSAMMLERISTTEMP, Type::et_dec_val},
        {Property::kSPEICHERISTTEMP, Type::et_dec_val},
        {Property::kVORLAUFISTTEMP, Type::et_dec_val},
        {Property::kRAUMISTTEMP, Type::et_dec_val},
        {Property::kVERSTELLTE_RAUMSOLLTEMP, Type::et_dec_val},
        {Property::kEINSTELL_SPEICHERSOLLTEMP, Type::et_dec_val},
        {Property::kVERDAMPFERTEMP, Type::et_dec_val},
        {Property::kSAMMLERSOLLTEMP, Type::et_dec_val},
        {Property::kRUECKLAUFISTTEMP, Type::et_dec_val},
        {Property::kSPEICHER_UNTEN_TEMP, Type::et_dec_val},
        {Property::kSOLARZONENTEMP, Type::et_dec_val},
        {Property::kSPEICHER_OBEN_TEMP, Type::et_dec_val},
        {Property::kKOLLEKTORTEMP, Type::et_dec_val},
        {Property::kFESTSTOFFKESSELTEMP, Type::et_dec_val},
        {Property::kMIN_TEMP_KESSEL, Type::et_dec_val},
        {Property::kANFAHRTEMP, Type::et_dec_val},
        {Property::kHYSTERESEZEIT, Type::et_dec_val},
        {Property::kMAX_HYSTERESE, Type::et_little_endian},
        {Property::kMAX_TEMP_KESSEL, Type::et_dec_val},
        {Property::kMAX_TEMP_HZK, Type::et_dec_val},
        {Property::kTN, Type::et_little_endian},
        {Property::kACCESS_EEPROM, Type::et_little_endian},
        {Property::kKOLLEKTORTEMP_2, Type::et_dec_val},
        {Property::kMULTIFUNKTION_ISTTEMP, Type::et_dec_val},
        {Property::kBRENNER, Type::et_little_endian},
        {Property::kDCF, Type::et_little_endian},
        {Property::kMISCHER_AUF, Type::et_little_endian},
        {Property::kMISCHER_ZU, Type::et_little_endian},
        {Property::kHEIZKREIS_STATUS, Type::et_little_endian},
        {Property::kSPEICHER_STATUS, Type::et_little_endian},
        {Property::kWAERMEPUMPEN_STATUS, Type::et_little_endian},
        {Property::kKESSELSTATUS, Type::et_little_endian},
        {Property::kMISCHERSTATUS, Type::et_little_endian},
        {Property::kSONDERKREIS_STATUS, Type::et_little_endian},
        {Property::kFEUCHTE, Type::et_dec_val},
        {Property::kPUFFERTEMP_OBEN1, Type::et_dec_val},
        {Property::kPUFFERTEMP_MITTE1, Type::et_dec_val},
        {Property::kPUFFERTEMP_UNTEN1, Type::et_dec_val},
        {Property::kPUFFERTEMP_OBEN2, Type::et_dec_val},
        {Property::kPUFFERTEMP_MITTE2, Type::et_dec_val},
        {Property::kPUFFERTEMP_UNTEN2, Type::et_dec_val},
        {Property::kPUFFERTEMP_OBEN3, Type::et_dec_val},
        {Property::kPUFFERTEMP_MITTE3, Type::et_dec_val},
        {Property::kPUFFERTEMP_UNTEN3, Type::et_dec_val},
        {Property::kSOLAR_TAGESERTRAG_KWH, Type::et_double_val},
        {Property::kSOLAR_GESAMTERTRAG_KWH, Type::et_double_val},
        {Property::kSOLAR_GESAMTERTRAG_MWH, Type::et_triple_val},
        {Property::kINITIALISIERUNG, Type::et_little_endian},
        {Property::kAUSSENTEMPVERZOEGERUNG, Type::et_dec_val},
        {Property::kHEIZKURVE, Type::et_cent_val},
        {Property::kHZK_KURVENABSTAND, Type::et_dec_val},
        {Property::kPROGRAMMSCHALTER, Type::et_betriebsart},
        {Property::kSPRACHE, Type::et_little_endian},
        {Property::kAUSWAHL_STANDARDTEMP, Type::et_dec_val},
        {Property::kESTRICHFUNKTION, Type::et_little_endian},
        {Property::kFERIENANFANG_TAG, Type::et_little_endian},
        {Property::kFERIENANFANG_MONAT, Type::et_little_endian},
        {Property::kFERIENANFANG_JAHR, Type::et_little_endian},
        {Property::kFERIENENDE_TAG, Type::et_little_endian},
        {Property::kFERIENENDE_MONAT, Type::et_little_endian},
        {Property::kFERIENENDE_JAHR, Type::et_little_endian},
        {Property::kWOCHENTAG, Type::et_little_endian},
        {Property::kTAG, Type::et_little_endian},
        {Property::kMONAT, Type::et_little_endian},
        {Property::kJAHR, Type::et_little_endian},
        {Property::kSTUNDE, Type::et_little_endian},
        {Property::kMINUTE, Type::et_little_endian},
        {Property::kSEKUNDE, Type::et_little_endian},
        {Property::kMIN_TEMP_HZK, Type::et_dec_val},
        {Property::kFERIEN_ABSENKTEMP, Type::et_dec_val},
        {Property::kWW_MAXTEMP, Type::et_dec_val},
        {Property::kWARMWASSERMODE, Type::et_little_endian},
        {Property::kKESSELSOLLTEMP_2WE, Type::et_dec_val},
        {Property::kABWESENHEITSTEMP, Type::et_dec_val},
        {Property::kEINSTELL_SPEICHERSOLLTEMP3, Type::et_dec_val},
        {Property::kABGASTEMP, Type::et_dec_val},
        {Property::kGERAETEKONFIGURATION_2, Type::et_little_endian},
        {Property::kWW_SCHNELL_START_TEMPERATUR, Type::et_dec_val},
        {Property::kMAX_WW_TEMP, Type::et_dec_val},
        {Property::kBIVALENTPARALLELTEMPERATUR_HZG, Type::et_dec_val},
        {Property::kBIVALENTPARALLELTEMPERATUR_WW, Type::et_dec_val},
        {Property::kBIVALENZALTERNATIVTEMPERATUR_HZG, Type::et_dec_val},
        {Property::kBIVALENZALTERNATIVTEMPERATUR_WW, Type::et_dec_val},
        {Property::kQUELLENSOLLTEMPERATUR, Type::et_dec_val},
        {Property::kAUSSENTEMPERATUR_WARMWASSER, Type::et_dec_val},
        {Property::kSOLARDIFFERENZ, Type::et_dec_val},
        {Property::kSOLARTEMP_MAX, Type::et_dec_val},
        {Property::kESTRICH_SOCKELTEMPERATUR, Type::et_dec_val},
        {Property::kESTRICH_MAX_TEMPERATUR, Type::et_dec_val},
        {Property::kSW_AUSSENTEMP, Type::et_dec_val},
        {Property::kFESTWERT, Type::et_little_endian},
        {Property::kPUMPENSTATUS, Type::et_little_endian},
        {Property::kQUELLE_IST, Type::et_dec_val},
        {Property::kPUFFERSOLL, Type::et_dec_val},
        {Property::kWPVORLAUFIST, Type::et_dec_val},
        {Property::kHILFSKESSELSOLL, Type::et_dec_val},
        {Property::kFUEHLER_1, Type::et_dec_val},
        {Property::kFUEHLER_2, Type::et_dec_val},
        {Property::kVOLUMENSTROM, Type::et_dec_val},
        {Property::kMAX_HEIZUNG_TEMP, Type::et_dec_val},
        {Property::kVORLAUFSOLL_GEBLAESE, Type::et_dec_val},
        {Property::kRAUMSOLL_GEBLAESE, Type::et_dec_val},
        {Property::kHYSTERESE_GEBLAESE, Type::et_dec_val},
        {Property::kVORLAUFSOLL_FLAECHE, Type::et_dec_val},
        {Property::kRAUMSOLL_FLAECHE, Type::et_dec_val},
        {Property::kTAUPUNKT_TEMP, Type::et_dec_val},
        {Property::kHEISSGAS_TEMP, Type::et_dec_val},
        {Property::kWW_ECO, Type::et_bool},
        {Property::kSOLAR_WOCHENERTRAG_KWH, Type::et_double_val},
        {Property::kSOLAR_WOCHENERTRAG_MWH, Type::et_triple_val},
        {Property::kSOLAR_JAHRESERTRAG_KWH, Type::et_double_val},
        {Property::kSOLAR_JAHRESERTRAG_MWH, Type::et_triple_val},
        {Property::kSOLAR_KOLLEKTORSCHUTZTEMP, Type::et_dec_val},
        {Property::kANZEIGE_HOCHDRUCK, Type::et_dec_val},
        {Property::kANZEIGE_NIEDERDRUCK, Type::et_dec_val},
        {Property::kVERDICHTER, Type::et_dec_val},
        {Property::kLZ_VERD_1_HEIZBETRIEB, Type::et_mil_val},
        {Property::kLZ_VERD_2_HEIZBETRIEB, Type::et_mil_val},
        {Property::kLZ_VERD_1_2_HEIZBETRIEB, Type::et_mil_val},
        {Property::kLZ_VERD_1_KUEHLBETRIEB, Type::et_mil_val},
        {Property::kLZ_VERD_2_KUEHLBETRIEB, Type::et_mil_val},
        {Property::kLZ_VERD_1_2_KUEHLBETRIEB, Type::et_mil_val},
        {Property::kVORLAUFISTTEMP_WP_IWS, Type::et_dec_val},
        {Property::kRUECKLAUFISTTEMP_WP_IWS, Type::et_dec_val},
        {Property::kEL_AUFNAHMELEISTUNG_WW_TAG_KWH, Type::et_double_val},
        {Property::kEL_AUFNAHMELEISTUNG_WW_SUM_MWH, Type::et_double_val},
        {Property::kEL_AUFNAHMELEISTUNG_HEIZ_TAG_KWH, Type::et_double_val},
        {Property::kEL_AUFNAHMELEISTUNG_HEIZ_SUM_MWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_2WE_WW_TAG_KWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_2WE_WW_SUM_MWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_2WE_HEIZ_TAG_KWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_2WE_HEIZ_SUM_MWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_WW_TAG_KWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_WW_SUM_MWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_HEIZ_TAG_KWH, Type::et_double_val},
        {Property::kWAERMEERTRAG_HEIZ_SUM_MWH, Type::et_double_val},
        {Property::kAUSSEN_FROSTTEMP, Type::et_dec_val},
        {Property::kEINSTELL_SPEICHERSOLLTEMP2, Type::et_dec_val},
        {Property::kFEHLERFELD_5, Type::et_dev_nr},
        {Property::kFEHLERFELD_6, Type::et_err_nr},
        {Property::kFEHLERFELD_12, Type::et_dev_nr},
        {Property::kFEHLERFELD_13, Type::et_err_nr},
        {Property::kFEHLERFELD_19, Type::et_dev_nr},
        {Property::kFEHLERFELD_20, Type::et_err_nr},
        {Property::kFEHLERFELD_26, Type::et_dev_nr},
        {Property::kFEHLERFELD_27, Type::et_err_nr},
        {Property::kFEHLERFELD_33, Type::et_dev_nr},
        {Property::kFEHLERFELD_34, Type::et_err_nr},
        {Property::kFEHLERFELD_40, Type::et_dev_nr},
        {Property::kFEHLERFELD_41, Type::et_err_nr},
        {Property::kFEHLERFELD_47, Type::et_dev_nr},
        {Property::kFEHLERFELD_48, Type::et_err_nr},
        {Property::kFEHLERFELD_54, Type::et_dev_nr},
        {Property::kFEHLERFELD_55, Type::et_err_nr},
        {Property::kFEHLERFELD_61, Type::et_dev_nr},
        {Property::kFEHLERFELD_62, Type::et_err_nr},
        {Property::kFEHLERFELD_68, Type::et_dev_nr},
        {Property::kFEHLERFELD_69, Type::et_err_nr},
        {Property::kFEHLERFELD_75, Type::et_dev_nr},
        {Property::kFEHLERFELD_76, Type::et_err_nr},
        {Property::kFEHLERFELD_82, Type::et_dev_nr},
        {Property::kFEHLERFELD_83, Type::et_err_nr},
        {Property::kFEHLERFELD_89, Type::et_dev_nr},
        {Property::kFEHLERFELD_90, Type::et_err_nr},
        {Property::kFEHLERFELD_96, Type::et_dev_nr},
        {Property::kFEHLERFELD_97, Type::et_err_nr},
        {Property::kFEHLERFELD_103, Type::et_dev_nr},
        {Property::kFEHLERFELD_104, Type::et_err_nr},
        {Property::kFEHLERFELD_110, Type::et_dev_nr},
        {Property::kFEHLERFELD_111, Type::et_err_nr},
        {Property::kFEHLERFELD_117, Type::et_dev_nr},
        {Property::kFEHLERFELD_118, Type::et_err_nr},
        {Property::kFEHLERFELD_124, Type::et_dev_nr},
        {Property::kFEHLERFELD_125, Type::et_err_nr},
        {Property::kFEHLERFELD_131, Type::et_dev_nr},
        {Property::kFEHLERFELD_132, Type::et_err_nr},
        {Property::kFEHLERFELD_138, Type::et_dev_nr},
        {Property::kFEHLERFELD_139, Type::et_err_nr},
        {Property::kHEIZPROG_1_MO, Type::et_time_domain},
        {Property::kHEIZPROG_1_MO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_MO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_1_DI, Type::et_time_domain},
        {Property::kHEIZPROG_1_DI_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_DI_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_1_MI, Type::et_time_domain},
        {Property::kHEIZPROG_1_MI_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_MI_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_1_DO, Type::et_time_domain},
        {Property::kHEIZPROG_1_DO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_DO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_1_FR, Type::et_time_domain},
        {Property::kHEIZPROG_1_FR_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_FR_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_1_SA, Type::et_time_domain},
        {Property::kHEIZPROG_1_SA_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_SA_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_1_SO, Type::et_time_domain},
        {Property::kHEIZPROG_1_SO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_1_SO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_MO, Type::et_time_domain},
        {Property::kHEIZPROG_2_MO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_MO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_DI, Type::et_time_domain},
        {Property::kHEIZPROG_2_DI_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_DI_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_MI, Type::et_time_domain},
        {Property::kHEIZPROG_2_MI_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_MI_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_DO, Type::et_time_domain},
        {Property::kHEIZPROG_2_DO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_DO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_FR, Type::et_time_domain},
        {Property::kHEIZPROG_2_FR_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_FR_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_SA, Type::et_time_domain},
        {Property::kHEIZPROG_2_SA_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_SA_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_2_SO, Type::et_time_domain},
        {Property::kHEIZPROG_2_SO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_2_SO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_MO, Type::et_time_domain},
        {Property::kHEIZPROG_3_MO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_MO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_DI, Type::et_time_domain},
        {Property::kHEIZPROG_3_DI_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_DI_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_MI, Type::et_time_domain},
        {Property::kHEIZPROG_3_MI_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_MI_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_DO, Type::et_time_domain},
        {Property::kHEIZPROG_3_DO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_DO_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_FR, Type::et_time_domain},
        {Property::kHEIZPROG_3_FR_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_FR_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_SA, Type::et_time_domain},
        {Property::kHEIZPROG_3_SA_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_SA_SCHALT_3, Type::et_time_domain},
        {Property::kHEIZPROG_3_SO, Type::et_time_domain},
        {Property::kHEIZPROG_3_SO_SCHALT_2, Type::et_time_domain},
        {Property::kHEIZPROG_3_SO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_MO, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_MO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_MO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_DI, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_DI_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_DI_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_MI, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_MI_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_MI_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_DO, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_DO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_DO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_FR, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_FR_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_FR_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_SA, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_SA_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_SA_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_SO, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_SO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_1_SO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_MO, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_MO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_MO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_DI, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_DI_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_DI_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_MI, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_MI_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_MI_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_DO, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_DO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_DO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_FR, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_FR_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_FR_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_SA, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_SA_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_SA_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_SO, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_SO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_2_SO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_MO, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_MO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_MO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_DI, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_DI_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_DI_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_MI, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_MI_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_MI_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_DO, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_DO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_DO_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_FR, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_FR_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_FR_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_SA, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_SA_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_SA_SCHALT_3, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_SO, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_SO_SCHALT_2, Type::et_time_domain},
        {Property::kW_WASSERPROG_3_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_MO, Type::et_time_domain},
        {Property::kZIRKPROG_1_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_DI, Type::et_time_domain},
        {Property::kZIRKPROG_1_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_MI, Type::et_time_domain},
        {Property::kZIRKPROG_1_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_DO, Type::et_time_domain},
        {Property::kZIRKPROG_1_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_FR, Type::et_time_domain},
        {Property::kZIRKPROG_1_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_SA, Type::et_time_domain},
        {Property::kZIRKPROG_1_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_1_SO, Type::et_time_domain},
        {Property::kZIRKPROG_1_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_1_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_MO, Type::et_time_domain},
        {Property::kZIRKPROG_2_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_DI, Type::et_time_domain},
        {Property::kZIRKPROG_2_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_MI, Type::et_time_domain},
        {Property::kZIRKPROG_2_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_DO, Type::et_time_domain},
        {Property::kZIRKPROG_2_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_FR, Type::et_time_domain},
        {Property::kZIRKPROG_2_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_SA, Type::et_time_domain},
        {Property::kZIRKPROG_2_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_2_SO, Type::et_time_domain},
        {Property::kZIRKPROG_2_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_2_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_MO, Type::et_time_domain},
        {Property::kZIRKPROG_3_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_DI, Type::et_time_domain},
        {Property::kZIRKPROG_3_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_MI, Type::et_time_domain},
        {Property::kZIRKPROG_3_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_DO, Type::et_time_domain},
        {Property::kZIRKPROG_3_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_FR, Type::et_time_domain},
        {Property::kZIRKPROG_3_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_SA, Type::et_time_domain},
        {Property::kZIRKPROG_3_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZIRKPROG_3_SO, Type::et_time_domain},
        {Property::kZIRKPROG_3_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZIRKPROG_3_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_MO, Type::et_time_domain},
        {Property::kZBV_PROG_1_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_DI, Type::et_time_domain},
        {Property::kZBV_PROG_1_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_MI, Type::et_time_domain},
        {Property::kZBV_PROG_1_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_DO, Type::et_time_domain},
        {Property::kZBV_PROG_1_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_FR, Type::et_time_domain},
        {Property::kZBV_PROG_1_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_SA, Type::et_time_domain},
        {Property::kZBV_PROG_1_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_1_SO, Type::et_time_domain},
        {Property::kZBV_PROG_1_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_1_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_MO, Type::et_time_domain},
        {Property::kZBV_PROG_2_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_DI, Type::et_time_domain},
        {Property::kZBV_PROG_2_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_MI, Type::et_time_domain},
        {Property::kZBV_PROG_2_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_DO, Type::et_time_domain},
        {Property::kZBV_PROG_2_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_FR, Type::et_time_domain},
        {Property::kZBV_PROG_2_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_SA, Type::et_time_domain},
        {Property::kZBV_PROG_2_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZBV_PROG_2_SO, Type::et_time_domain},
        {Property::kZBV_PROG_2_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZBV_PROG_2_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_MO, Type::et_time_domain},
        {Property::kZEITPROG_1_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_DI, Type::et_time_domain},
        {Property::kZEITPROG_1_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_MI, Type::et_time_domain},
        {Property::kZEITPROG_1_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_DO, Type::et_time_domain},
        {Property::kZEITPROG_1_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_FR, Type::et_time_domain},
        {Property::kZEITPROG_1_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_SA, Type::et_time_domain},
        {Property::kZEITPROG_1_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_1_SO, Type::et_time_domain},
        {Property::kZEITPROG_1_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_1_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_MO, Type::et_time_domain},
        {Property::kZEITPROG_2_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_DI, Type::et_time_domain},
        {Property::kZEITPROG_2_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_MI, Type::et_time_domain},
        {Property::kZEITPROG_2_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_DO, Type::et_time_domain},
        {Property::kZEITPROG_2_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_FR, Type::et_time_domain},
        {Property::kZEITPROG_2_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_SA, Type::et_time_domain},
        {Property::kZEITPROG_2_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_2_SO, Type::et_time_domain},
        {Property::kZEITPROG_2_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_2_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_MO, Type::et_time_domain},
        {Property::kZEITPROG_3_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_DI, Type::et_time_domain},
        {Property::kZEITPROG_3_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_MI, Type::et_time_domain},
        {Property::kZEITPROG_3_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_DO, Type::et_time_domain},
        {Property::kZEITPROG_3_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_FR, Type::et_time_domain},
        {Property::kZEITPROG_3_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_SA, Type::et_time_domain},
        {Property::kZEITPROG_3_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_3_SO, Type::et_time_domain},
        {Property::kZEITPROG_3_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_3_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_MO, Type::et_time_domain},
        {Property::kZEITPROG_4_MO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_MO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_DI, Type::et_time_domain},
        {Property::kZEITPROG_4_DI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_DI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_MI, Type::et_time_domain},
        {Property::kZEITPROG_4_MI_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_MI_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_DO, Type::et_time_domain},
        {Property::kZEITPROG_4_DO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_DO_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_FR, Type::et_time_domain},
        {Property::kZEITPROG_4_FR_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_FR_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_SA, Type::et_time_domain},
        {Property::kZEITPROG_4_SA_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_SA_SCHALT_3, Type::et_time_domain},
        {Property::kZEITPROG_4_SO, Type::et_time_domain},
        {Property::kZEITPROG_4_SO_SCHALT_2, Type::et_time_domain},
        {Property::kZEITPROG_4_SO_SCHALT_3, Type::et_time_domain},
        {Property::kZWEITER_WE_STATUS, Type::et_little_endian},
        {Property::kWP_EVU, Type::et_little_endian},
        {Property::kWP_PUMPENSTATUS, Type::et_little_endian},
        {Property::kWP_STATUS, Type::et_little_endian},
        {Property::kDAUERLAUF_PUFFERLADEPUMPE, Type::et_little_endian},
        {Property::kSCHALTWERKDYNAMIKZEIT, Type::et_little_endian},
        {Property::kSTILLSTANDZEIT_0, Type::et_little_endian},
        {Property::kPUMPENZYKLEN, Type::et_little_endian},
        {Property::kGEBAEUDEART, Type::et_little_endian},
        {Property::kSOMMERBETRIEB, Type::et_little_bool},
        {Property::kIMPULSRATE, Type::et_little_endian},
        {Property::kSOLARBETRIEB, Type::et_little_endian},
        {Property::kWAERMEMENGE, Type::et_little_endian},
        {Property::kAUTOMATIK_WARMWASSER, Type::et_little_bool},
        {Property::kWPSTUFEN_WW, Type::et_little_endian},
        {Property::kWW_MIT_2WE, Type::et_little_endian},
        {Property::kSPERREN_2WE, Type::et_little_endian},
        {Property::kFREIGABE_2WE, Type::et_little_endian},
        {Property::kDYNAMIK, Type::et_little_endian},
        {Property::kBETRIEBSART_HZK_PUMPE, Type::et_little_endian},
        {Property::kDRUCK_HEIZKREIS, Type::et_dec_val},
        {Property::kPUMPENDREHZAHL_HEIZEN, Type::et_dec_val},
        {Property::kRAUMEINFLUSS, Type::et_little_endian}
    };
}
