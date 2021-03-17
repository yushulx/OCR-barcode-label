#pragma once

#if !defined(_WIN32) && !defined(_WIN64)
#define DLR_API __attribute__((visibility("default")))
#include <stddef.h>
#else
#ifdef DLR_EXPORTS
#define DLR_API __declspec(dllexport)
#else
#define DLR_API 
#endif
#include <windows.h>
#endif


#define DLR_VERSION                  "1.0.0.0202"

/**Successful. */
#define DLR_OK									 0 

/**Unknown error. */
#define DLRERR_UNKNOWN						-10000 

/**Not enough memory to perform the operation. */
#define DLRERR_NO_MEMORY					-10001 

/**Null pointer */
#define DLRERR_NULL_POINTER				-10002 

/**License invalid*/
#define DLRERR_LICENSE_INVALID				-10003 

/**File not found*/
#define DLRERR_FILE_NOT_FOUND				-10004 

/**Json parse failed*/
#define DLRERR_JSON_PARSE_FAILED			-10005 

/**Json type invalid*/
#define DLRERR_JSON_TYPE_INVALID			-10006 

/**Json key invalid*/
#define DLRERR_JSON_KEY_INVALID			-10007 

/**Json value invalid*/
#define DLRERR_JSON_VALUE_INVALID			-10008 

/**Json name key missing*/
#define DLRERR_JSON_NAME_KEY_MISSING           -10009

/**The value of the key "Name" is duplicated.*/
#define DLRERR_JSON_NAME_VALUE_DUPLICATED    -10010

/**Parameter value invalid*/
#define DLRERR_PARAMETER_VALUE_INVALID -10011

/**Template name invalid*/
#define DLRERR_TEMPLATE_NAME_INVALID -10012

/**License expired*/
#define DLRERR_LICENSE_EXPIRED -10013

/**Character Model file is not found*/
#define DLRERR_CHARACTER_MODEL_FILE_NOT_FOUND -10014

/**Failed to set mode's argument.*/
#define DLRERR_SET_MODE_ARGUMENT_ERROR -10015

/**Failed to get mode's argument.*/
#define DLRERR_GET_MODE_ARGUMENT_ERROR -10016

/**
* @enum DLRImagePixelFormat
*
* Describes the image pixel format.
*
*/
typedef enum DLRImagePixelFormat
{
	/**0:Black, 1:White */
	DLR_IPF_BINARY,

	/**0:White, 1:Black */
	DLR_IPF_BINARYINVERTED,

	/**8bit gray */
	DLR_IPF_GRAYSCALED,

	/**NV21 */
	DLR_IPF_NV21,

	/**16bit with RGB channel order stored in memory from high to low address*/
	DLR_IPF_RGB_565,

	/**16bit with RGB channel order stored in memory from high to low address*/
	DLR_IPF_RGB_555,

	/**24bit with RGB channel order stored in memory from high to low address*/
	DLR_IPF_RGB_888,

	/**32bit with ARGB channel order stored in memory from high to low address*/
	DLR_IPF_ARGB_8888,

	/**48bit with RGB channel order stored in memory from high to low address*/
	DLR_IPF_RGB_161616,

	/**64bit with ARGB channel order stored in memory from high to low address*/
	DLR_IPF_ARGB_16161616,

	/**32bit with ABGR channel order stored in memory from high to low address*/
	DLR_IPF_ABGR_8888,

	/**64bit with ABGR channel order stored in memory from high to low address*/
	DLR_IPF_ABGR_16161616,

	/**24bit with BGR channel order stored in memory from high to low address*/
	DLR_IPF_BGR_888

}DLRImagePixelFormat;

///**
//* @enum DLRTextColourMode
//*
//* Describes the text colour mode.
//*
//*/
//typedef enum
//{
//	/**Dark items on a light background*/
//	DLR_TCM_DARK_ON_LIGHT = 1,
//
//	/**Light items on a dark background*/
//	DLR_TCM_LIGHT_ON_DARK = 2,
//
//	/**Skip*/
//	DLR_TCM_SKIP = 0
//}DLRTextColourMode;

/**
* @enum DLRGrayscaleTransformationMode
*
* Describes the grayscale transformation mode.
*/
typedef enum DLRGrayscaleTransformationMode
{
	/**Transforms to inverted grayscale. Recommended for light on dark images. */
	DLR_GTM_INVERTED = 0x01,

	/**Keeps the original grayscale. Recommended for dark on light images. */
	DLR_GTM_ORIGINAL = 0x02,

	/**Lets the library choose an algorithm automatically for grayscale transformation.*/
	DLR_GTM_AUTO = 0x04,

	/**Reserved setting for grayscale transformation mode.*/
#if defined(_WIN32) || defined(_WIN64)
	DLR_GTM_REV = 0x80000000,
#else
	DLR_GTM_REV = -2147483648,
#endif

	/**Skips grayscale transformation. */
	DLR_GTM_SKIP = 0x00

}DLRGrayscaleTransformationMode;

/**
* @enum DLRRegionPredetectionMode
*
* Describes the region predetection mode.
*
*/
typedef enum DLRRegionPredetectionMode
{
	/**Auto*/
	DLR_RPM_AUTO = 0x01, 

	/**Takes the whole image as a region*/
	DLR_RPM_GENERAL = 0x02,

	/**Detects region using the general algorithm based on RGB colour contrast*/
	DLR_RPM_GENERAL_RGB_CONTRAST = 0x04,

	/**Detects region using the general algorithm based on gray contrast*/
	DLR_RPM_GENERAL_GRAY_CONTRAST = 0x08,

	/**Detects region using the general algorithm based on HSV colour contrast*/
	DLR_RPM_GENERAL_HSV_CONTRAST = 0x10,

	/**Reserved setting for region predection mode.*/
#if defined(_WIN32) || defined(_WIN64)
	DLR_RPM_REV = 0x80000000,
#else
	DLR_RPM_REV = -2147483648,
#endif

	/**Skip*/
	DLR_RPM_SKIP = 0
}DLRRegionPredetectionMode;

/**
* @enum DLRBinarizationMode
*
* Describes the binarization mode.
*
*/
typedef enum DLRBinarizationMode
{
	/**Not supported yet. */
	DLR_BM_AUTO = 0x01,

	/**Binarizes the image based on the local block. Check @ref BM for available argument settings.*/
	DLR_BM_LOCAL_BLOCK = 0x02,

	/**Performs image binarization based on the given threshold. Check @ref BM for available argument settings.*/
	DLR_BM_THRESHOLD = 0x04,

	/**Reserved setting for binarization mode.*/
#if defined(_WIN32) || defined(_WIN64)
	DLR_BM_REV = 0x80000000,
#else
	DLR_BM_REV = -2147483648,
#endif

	/**Skips the binarization. */
	DLR_BM_SKIP = 0x00
}DLRBinarizationMode;

/**
* @enum DLRImagePreprocessingMode
*
* Describes the image preprocessing mode.
*
*/
typedef enum DLRImagePreprocessingMode
{
	/**Not supported yet. */
	DLR_IPM_AUTO = 0x01,

	/**Takes the unpreprocessed image for following operations. */
	DLR_IPM_GENERAL = 0x02,

	/**Preprocesses the image using the gray equalization algorithm. Check @ref IPM for available argument settings.*/
	DLR_IPM_GRAY_EQUALIZE = 0x04,

	/**Preprocesses the image using the gray smoothing algorithm. Check @ref IPM for available argument settings.*/
	DLR_IPM_GRAY_SMOOTH = 0x08,

	/**Preprocesses the image using the sharpening and smoothing algorithm. Check @ref IPM for available argument settings.*/
	DLR_IPM_SHARPEN_SMOOTH = 0x10,

	/**Preprocesses the image using the morphology algorithm. Check @ref IPM for available argument settings.*/
	DLR_IPM_MORPHOLOGY = 0x20,

	/**Reserved setting for image preprocessing mode.*/
#if defined(_WIN32) || defined(_WIN64)
	DLR_IPM_REV = 0x80000000,
#else
	DLR_IPM_REV = -2147483648,
#endif

	/**Skips image preprocessing. */
	DLR_IPM_SKIP = 0x00
}DLRImagePreprocessingMode;

/**
* @enum DLRLocalizationSourceType
*
* Describes localization source type.
*
*/
typedef enum DLRLocalizationSourceType
{
	DLR_LST_MANUAL_SPECIFICATION = 0x01,
	DLR_LST_PREDETECTED_REGION = 0x02,
	DLR_LST_BARCODE = 0x04
}DLRLocalizationSourceType;

/**
* @enum BarcodeFormat
*
* Describes the barcode types in BarcodeFormat group 1. All the formats can be combined, such as DLR_BF_CODE_39 | DLR_BF_CODE_128.
* Note: The barcode format our library will search for is composed of [BarcodeFormat group 1](@ref BarcodeFormat) and [BarcodeFormat group 2](@ref BarcodeFormat_2), so you need to specify the barcode format in group 1 and group 2 individually.
*/
typedef enum DLRBarcodeFormat
{
	/**All supported formats in BarcodeFormat group 1*/
#if defined(_WIN32) || defined(_WIN64)
	DLR_BF_ALL = 0xFE1FFFFF,
#else
	DLR_BF_ALL = -31457281,
#endif

	/**Combined value of DLR_BF_CODABAR, DLR_BF_CODE_128, DLR_BF_CODE_39, DLR_BF_CODE_39_Extended, DLR_BF_CODE_93, DLR_BF_EAN_13, DLR_BF_EAN_8, INDUSTRIAL_25, DLR_BF_ITF, DLR_BF_UPC_A, DLR_BF_UPC_E, DLR_BF_MSI_CODE;  */
	DLR_BF_ONED = 0x001007FF,

	/**Combined value of DLR_BF_GS1_DATABAR_OMNIDIRECTIONAL, DLR_BF_GS1_DATABAR_TRUNCATED, DLR_BF_GS1_DATABAR_STACKED, DLR_BF_GS1_DATABAR_STACKED_OMNIDIRECTIONAL, DLR_BF_GS1_DATABAR_EXPANDED, DLR_BF_GS1_DATABAR_EXPANDED_STACKED, DLR_BF_GS1_DATABAR_LIMITED*/
	DLR_BF_GS1_DATABAR = 0x0003F800,

	/**Code 39 */
	DLR_BF_CODE_39 = 0x1,

	/**Code 128 */
	DLR_BF_CODE_128 = 0x2,

	/**Code 93 */
	DLR_BF_CODE_93 = 0x4,

	/**Codabar */
	DLR_BF_CODABAR = 0x8,

	/**Interleaved 2 of 5 */
	DLR_BF_ITF = 0x10,

	/**EAN-13 */
	DLR_BF_EAN_13 = 0x20,

	/**EAN-8 */
	DLR_BF_EAN_8 = 0x40,

	/**UPC-A */
	DLR_BF_UPC_A = 0x80,

	/**UPC-E */
	DLR_BF_UPC_E = 0x100,

	/**Industrial 2 of 5 */
	DLR_BF_INDUSTRIAL_25 = 0x200,

	/**CODE39 Extended */
	DLR_BF_CODE_39_EXTENDED = 0x400,

	/**GS1 Databar Omnidirectional*/
	DLR_BF_GS1_DATABAR_OMNIDIRECTIONAL = 0x800,

	/**GS1 Databar Truncated*/
	DLR_BF_GS1_DATABAR_TRUNCATED = 0x1000,

	/**GS1 Databar Stacked*/
	DLR_BF_GS1_DATABAR_STACKED = 0x2000,

	/**GS1 Databar Stacked Omnidirectional*/
	DLR_BF_GS1_DATABAR_STACKED_OMNIDIRECTIONAL = 0x4000,

	/**GS1 Databar Expanded*/
	DLR_BF_GS1_DATABAR_EXPANDED = 0x8000,

	/**GS1 Databar Expaned Stacked*/
	DLR_BF_GS1_DATABAR_EXPANDED_STACKED = 0x10000,

	/**GS1 Databar Limited*/
	DLR_BF_GS1_DATABAR_LIMITED = 0x20000,

	/**Patch code. */
	DLR_BF_PATCHCODE = 0x00040000,

	/**PDF417 */
	DLR_BF_PDF417 = 0x02000000,

	/**QRCode */
	DLR_BF_QR_CODE = 0x04000000,

	/**DataMatrix */
	DLR_BF_DATAMATRIX = 0x08000000,

	/**AZTEC */
	DLR_BF_AZTEC = 0x10000000,

	/**MAXICODE */
	DLR_BF_MAXICODE = 0x20000000,

	/**Micro QR Code*/
	DLR_BF_MICRO_QR = 0x40000000,

	/**Micro PDF417*/
	DLR_BF_MICRO_PDF417 = 0x00080000,

	/**GS1 Composite Code*/
#if defined(_WIN32) || defined(_WIN64)
	DLR_BF_GS1_COMPOSITE = 0x80000000,
#else
	DLR_BF_GS1_COMPOSITE = -2147483648,
#endif

	/**MSI Code*/
	DLR_BF_MSI_CODE = 0x100000,

	/**No barcode format in BarcodeFormat group 1*/
	DLR_BF_NULL = 0x00

}DLRBarcodeFormat;

/**
* @enum BarcodeFormat_2
*
* Describes the barcode types in BarcodeFormat group 2.
* Note: The barcode format our library will search for is composed of [BarcodeFormat group 1](@ref BarcodeFormat) and [BarcodeFormat group 2](@ref BarcodeFormat_2), so you need to specify the barcode format in group 1 and group 2 individually.
*/
typedef enum DLRBarcodeFormat_2
{
	/**No barcode format in BarcodeFormat group 2*/
	DLR_BF2_NULL = 0x00,

	/**Combined value of DLR_BF2_USPSINTELLIGENTMAIL, DLR_BF2_POSTNET, DLR_BF2_PLANET, DLR_BF2_AUSTRALIANPOST, DLR_BF2_RM4SCC.
	When you set this barcode format, the library will automatically add LM_STATISTICS_POSTAL_CODE to LocalizationModes if you doesn't set it.*/
	DLR_BF2_POSTALCODE = 0x01F00000,

	/**Nonstandard barcode */
	DLR_BF2_NONSTANDARD_BARCODE = 0x01,

	/**USPS Intelligent Mail.
	When you set this barcode format, the library will automatically add LM_STATISTICS_POSTAL_CODE to LocalizationModes if you doesn't set it.*/
	DLR_BF2_USPSINTELLIGENTMAIL = 0x00100000,

	/**Postnet.
	When you set this barcode format, the library will automatically add LM_STATISTICS_POSTAL_CODE to LocalizationModes if you doesn't set it.*/
	DLR_BF2_POSTNET = 0x00200000,

	/**Planet.
	When you set this barcode format, the library will automatically add LM_STATISTICS_POSTAL_CODE to LocalizationModes if you doesn't set it.*/
	DLR_BF2_PLANET = 0x00400000,

	/**Australian Post.
	When you set this barcode format, the library will automatically add LM_STATISTICS_POSTAL_CODE to LocalizationModes if you doesn't set it.*/
	DLR_BF2_AUSTRALIANPOST = 0x00800000,

	/**Royal Mail 4-State Customer Barcode.
	When you set this barcode format, the library will automatically add LM_STATISTICS_POSTAL_CODE to LocalizationModes if you doesn't set it.*/
	DLR_BF2_RM4SCC = 0x01000000,

	/**DotCode. When you set this barcode format, the library will automatically add LM_STATISTICS_MARKS to LocalizationModes if you doesn't set it.*/
	DLR_BF2_DOTCODE = 0x02
}DLRBarcodeFormat_2;

#pragma pack(push)
#pragma pack(1)

/**
* @struct DLRPoint
*
* Stores an x- and y-coordinate pair in two-dimensional space.
*
*/
typedef struct tagDLRPoint
{
	/**The X coordinate of the point.*/
	int x;

	/**The Y coordinate of the point.*/
	int y;
}DLRPoint;

/**
* @struct DLRImageData
*
* Stores the image data.
*
*/
typedef struct tagDLRImageData
{
	/**The length of the image data byte.*/
	int bytesLength;

	/**The image data content in a byte array.*/
	unsigned char* bytes;

	/**The width of the image in pixels.*/
	int width;

	/**The height of the image in pixels.*/
	int height;

	/**The stride(or scan width) of the image.*/
	int stride;

	/**The image pixel format used in the image byte array.*/
	DLRImagePixelFormat format;
}DLRImageData;

/**
* @struct DLRQuadrilateral
*
* Stores the quadrilateral.
*
*/
typedef struct tagDLRQuadrilateral
{
	/**The four points of the quadrilateral.*/
	DLRPoint points[4];

}DLRQuadrilateral;

/**
* @struct DLRRegion
*
* Stores the region info.
*
*/
typedef struct tagDLRReferenceRegion
{
	DLRLocalizationSourceType localizationSourceType;
	DLRPoint points[4];
	int regionMeasuredByPercentage;
	int regionPredetectionModesIndex;
	int barcodeFormatIds;
	int barcodeFormatIds_2;
	char barcodeTextRegExPattern[64];

	char reserved[64];
}DLRReferenceRegion;

/**
* @struct DLRRuntimeSettings
*
* Defines a struct to configure the runtime settings. These settings control the recognition process.
*
*/
typedef struct tagDLRRuntimeSettings
{
	/**Sets the number of the threads the algorithm will use to recognize text.*/
	int maxThreadCount;

	/**Sets the name of the CharacterModel.*/
	char characterModelName[64];

	/**Sets the text lines count of the text area.*/
	int linesCount;

	/**Sets the region predetection modes.
	*
	* @par Value range:
	* 	    Each array item can be any one of the DLRRegionPredetectionMode Enumeration items.
	* @par Default value:
	* 	    [DLR_RPM_GENERAL,DLR_RPM_SKIP,DLR_RPM_SKIP,DLR_RPM_SKIP,DLR_RPM_SKIP,DLR_RPM_SKIP,DLR_RPM_SKIP,DLR_RPM_SKIP]
	* @par Remarks:
	*     The array index represents the priority of the item. The smaller index is, the higher priority is.
	* @sa DLRRegionPredetectionMode
	*/
	DLRRegionPredetectionMode regionPredetectionModes[8];

	/**Sets the reference region to search for text.*/
	DLRReferenceRegion referenceRegion;

	/**Sets the text area relative to the reference region.*/
	DLRQuadrilateral textArea;

	/**Sets the mode and priority for the grayscale image conversion.
	*
	* @par Value range:
	* 	    Each array item can be any one of the DLRGrayscaleTransformationMode Enumeration items.
	* @par Default value:
	* 	    [DLR_GTM_ORIGINAL,DLR_GTM_SKIP,DLR_GTM_SKIP,DLR_GTM_SKIP,DLR_GTM_SKIP,DLR_GTM_SKIP,DLR_GTM_SKIP,DLR_GTM_SKIP]
	* @par Remarks:
	*     The array index represents the priority of the item. The smaller index is, the higher priority is.
	* @sa DLRGrayscaleTransformationMode
	*/
	DLRGrayscaleTransformationMode grayscaleTransformationModes[8];

	/**Reserved memory for the struct.*/
	char reserved[64];
}DLRRuntimeSettings;

/**
* @struct DLRCharacterResult
*
* Stores character result.
*
*/
typedef struct tagDLRCharacterResult
{
	/**The recognized character with highest confidence.*/
	char characterH;

	/**The recognized character with middle confidence.*/
	char characterM;

	/**The recognized character with lowest confidence.*/
	char characterL;

	/**The location of current character.*/
	DLRQuadrilateral location;

	/**Reserved memory for the struct.*/
	char reserved[32];
}DLRCharacterResult, *PDLRCharacterResult;

/**
* @struct DLRLineResult
*
* Stores line result.
*
*/
typedef struct tagLineResult
{
	/**The name of the line specification used to recognize current line result.*/
	const char* lineSpecificationName;

	/**The recognized text, ends by '\0'.*/
	const char* text;

	/**The character model used to recognize the text.*/
	const char* characterModelName;

	/**The localization of current line.*/
	DLRQuadrilateral location;

	/**The confidence of the result.*/
	int confidence;

	/**The character result count.*/
	int characterResultsCount;

	/**The character results array.*/
	PDLRCharacterResult* characterResults;

	/**Reserved memory for the struct.*/
	char reserved[64];
}DLRLineResult, *PDLRLineResult;

/**
* @struct DLRResult
*
* Stores result.
*
*/
typedef struct tagDLRResult
{
	/**The name of the reference region used to recognize current result.*/
	const char* refereneceRegionName;

	/**The name of the text area used to recognize current result.*/
	const char* textAreaName;

	/**The localization result.*/
	DLRQuadrilateral location;

	/**The confidence of the result.*/
	int confidence;

	/**The line result count.*/
	int lineResultsCount;

	/**The line results array.*/
	PDLRLineResult* lineResults;

	/**Reserved memory for the struct.*/
	char reserved[64];
}DLRResult, *PDLRResult;

/**
* @struct DLRResultArray
*
* Stores result array.
*
*/
typedef struct tagDLRResultArray
{
	/**The recognized results array.*/
	PDLRResult* results;

	/**The total count of recognized results.*/
	int resultsCount;
}DLRResultArray;

typedef struct tagTextResultArray TextResultArray;
typedef struct tagDM_LTSConnectionParameters DM_LTSConnectionParameters;

#pragma pack(pop)

#ifdef __cplusplus
extern "C" {
#endif

	/**
	* Returns the error info string.
	*
	* @param [in] errorCode The error code.
	*
	* @return The error message.
	*
	*/
	DLR_API const char* DLR_GetErrorString(const int errorCode);

	/**
	* Returns the version info of the SDK.
	*
	* @return The version info string.
	*
	*/
	DLR_API const char* DLR_GetVersion();

	/**
	* Creates a Dynamsoft DLR instance.
	*
	* @return An DLR instance. If failed, return NULL.
	*
	*/
	DLR_API void* DLR_CreateInstance();

	/**
	* Destorys an instance of Dynamsoft DLR instance.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	*
	*/
	DLR_API void DLR_DestroyInstance(void* recognizer);

	/**
	* Reads product key and activates the SDK. 
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] pLicense The product key.
	* 			   
	* @return Returns error code. Returns 0 if the function operates successfully. You can call 
	* 		   DLR_GetErrorString() to get detailed error message.
	*/
	DLR_API int DLR_InitLicense(void* recognizer, const char* pLicense);

	/**
	* Gets current settings and save it into a struct.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in, out] pSettings The struct of runtime settings.
	* 
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		   DLR_GetErrorString() to get detailed error message.
	*/
	DLR_API int DLR_GetRuntimeSettings(void* recognizer, DLRRuntimeSettings* pSettings);

	/**
	* Updates runtime settings with a given struct.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] pSettings The struct of runtime settings.
	* @param [in, out] errorMsgBuffer The buffer is allocated by caller and the recommended length is 256. The error message will be copied to the bufer.
	* @param [in] errorMsgBufferLen The length of the allocated buffer.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
	*/
	DLR_API int DLR_UpdateRuntimeSettings(void* recognizer, DLRRuntimeSettings* pSettings, char errorMsgBuffer[], const int errorMsgBufferLen);

	/**
	* Reset runtime settings.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	*
	*/
	DLR_API int DLR_ResetRuntimeSettings(void* recognizer);

	/**
	* Sets the optional argument for a specified mode in Modes parameters.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] pModesName The mode parameter name to set argument.
	* @param [in] index The array index of mode parameter to indicate a specific mode.
	* @param [in] pArgumentName The name of the argument to set.
	* @param [in] pArgumentValue The value of the argument to set.
	* @param [in,out] errorMsgBuffer The buffer is allocated by the caller and the recommended length is 256. The error message will be copied to the buffer.
	* @param [in] errorMsgBufferLen The length of the allocated buffer.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
	*
	*/
	DLR_API int DLR_SetModeArgument(void *recognizer, const char *pModesName, const int index, const char *pArgumentName, const char *pArgumentValue, char errorMsgBuffer[], const int errorMsgBufferLen);

	/**
	* Gets the optional argument for a specified mode in Modes parameters.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] pModesName The mode parameter name to get argument.
	* @param [in] index The array index of mode parameter to indicate a specific mode.
	* @param [in] pArgumentName The name of the argument to get.
	* @param [in,out] valueBuffer The buffer is allocated by caller and the recommended length is 480. The argument value would be copied to the buffer.
	* @param [in] valueBufferLen The length of allocated buffer.
	* @param [in,out] errorMsgBuffer The buffer is allocated by the caller and the recommended length is 256. The error message will be copied to the buffer.
	* @param [in] errorMsgBufferLen The length of the allocated buffer.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
	*
	*/
	DLR_API int DLR_GetModeArgument(void *recognizer, const char *pModesName, const int index, const char *pArgumentName, char valueBuffer[], const int valueBufferLen, char errorMsgBuffer[], const int errorMsgBufferLen);

	/**
	* Clear template settings.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	*
	*/
	DLR_API int DLR_ClearAppendedSettings(void* recognizer);

	/**
	* Appends DLRParameter settings in a string to the SDK object.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance. 
	* @param [in] content A json string that represents the content of the settings.
	* @param [in, out] errorMsgBuffer The buffer is allocated by caller and the recommended length is 256. The error message will be copied to the bufer.
	* @param [in] errorMsgBufferLen The length of the allocated buffer.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
	*
	*/
	DLR_API int DLR_AppendSettingsFromString(void* recognizer, const char* content, char errorMsgBuffer[], const int errorMsgBufferLen);

	/**
	* Output DLRParameter settings into a file(JSON file).
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] outputFilePath The output file path which stores settings.
	* @param [in] templateName The name of the template which is to be output.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		   DLR_GetErrorString() to get detailed error message.
	*/
	DLR_API int DLR_OutputSettingsToFile(void* recognizer, const char* outputFilePath, const char* templateName);

	/**
	* Recognizes text from memory buffer containing image pixels in defined format.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] pImageDate A struct of DLRImageData that represents an image.
	* @param [in] templateName The template name.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		   DLR_GetErrorString() to get detailed error message.
	*
	*/
	DLR_API int DLR_RecognizeByBuffer(void* recognizer, const DLRImageData* pImageData, const char* templateName);

	/**
	* Recognizes text from a specified image file.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param [in] fileName A string defining the file name.
	* @param [in] templateName The template name.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		   DLR_GetErrorString() to get detailed error message.
	*
	*/
	DLR_API int DLR_RecognizeByFile(void* recognizer, const char* fileName, const char* templateName);

	/**
	* Get all recognized results.
	*
	* @param [in] recognizer Handle of Dynamsoft DLR instance.
	* @param[in, out] pResults The results are allocated by our SDK and should be freed by calling the function DLR_FreeDLRResults.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		   DLR_GetErrorString() to get detailed error message.
	*
	*/
	DLR_API int DLR_GetAllDLRResults(void* recognizer, DLRResultArray** pResults);

	/**
	* Initializes a DM_LTSConnectionParameters struct with default values.
	*
	* @param [in, out] pLTSConnectionParameters The struct of DM_LTSConnectionParameters.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		  DLR_GetErrorString() to get detailed error message.
	*
	*/
	DLR_API int DLR_InitLTSConnectionParameters(DM_LTSConnectionParameters *pLTSConnectionParameters);

	/**
	* Initializes the label recognition license and connects to the specified server for online verification.
	*
	* @param [in] pLTSConnectionParameters The struct DM_LTSConnectionParameters with customized settings.
	* @param [in, out] errorMsgBuffer The buffer is allocated by caller and the recommending length is 256. The error message will be copied to the buffer.
	* @param [in] errorMsgBufferLen The length of allocated buffer.
	*
	* @return Returns error code. Returns 0 if the function operates successfully. You can call
	* 		  DLR_GetErrorString() to get detailed error message.
	*
	*/
	DLR_API int DLR_InitLicenseFromLTS(DM_LTSConnectionParameters *pLTSConnectionParameters, char errorMsgBuffer[], const int errorMsgBufferLen);

	/**
	* Free memory allocated for recognized results.
	*
	* @param[in] pResults Recognized results.
	*
	*/
	DLR_API void DLR_FreeDLRResults(DLRResultArray** pResults);

	/**
	*
	*
	*
	*
	*/
	DLR_API int DLR_UpdateReferenceRegionFromBarcodeResults(void* recognizer, TextResultArray* barcodeResults, const char * templateName);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

class LabelRecognitionInner;

namespace dynamsoft
{
	namespace dlr
	{

		class DLR_API CLabelRecognition
		{
		protected:
			LabelRecognitionInner * m_DLRInner;

		public:
			CLabelRecognition();

			~CLabelRecognition();

			/**
			* Returns the error info string.
			*
			* @param [in] errorCode The error code.
			*
			* @return The error message.
			*
			*/
			static const char* GetErrorString(const int errorCode);

			/**
			* Returns the version info of the SDK.
			*
			* @return The version info string.
			*
			*/
			static const char* GetVersion();

			/**
			* Reads product key and activates the SDK.
			*
			* @param [in] pLicense The product key.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*/
			int InitLicense(const char* pLicense);

			/**
			* Gets current settings and save it into a struct.
			*
			* @param [in, out] pSettings The struct of runtime settings.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*/
			int GetRuntimeSettings(DLRRuntimeSettings* pSettings);

			/**
			* Updates runtime settings with a given struct.
			*
			* @param [in] pSettings The struct of runtime settings.
			* @param [in, out] errorMsgBuffer The buffer is allocated by caller and the recommended length is 256. The error message will be copied to the bufer.
			* @param [in] errorMsgBufferLen The length of the allocated buffer.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
			*
			*/
			int UpdateRuntimeSettings(DLRRuntimeSettings* pSettings, char errorMsgBuffer[] = NULL, const int errorMsgBufferLen = 0);

			/**
			* Reset runtime settings.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*
			*/
			int ResetRuntimeSettings();

			/**
			* Sets the optional argument for a specified mode in Modes parameters.
			*
			* @param [in] pModesName The mode parameter name to set argument.
			* @param [in] index The array index of mode parameter to indicate a specific mode.
			* @param [in] pArgumentName The name of the argument to set.
			* @param [in] pArgumentValue The value of the argument to set.
			* @param [in,out] errorMsgBuffer The buffer is allocated by the caller and the recommended length is 256. The error message will be copied to the buffer.
			* @param [in] errorMsgBufferLen The length of the allocated buffer.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
			*
			*/
			int SetModeArgument(const char *pModesName, const int index, const char *pArgumentName, const char *pArgumentValue, char errorMsgBuffer[] = NULL, const int errorMsgBufferLen = 0);

			/**
			* Gets the optional argument for a specified mode in Modes parameters.
			*
			* @param [in] pModesName The mode parameter name to get argument.
			* @param [in] index The array index of mode parameter to indicate a specific mode.
			* @param [in] pArgumentName The name of the argument to get.
			* @param [in,out] valueBuffer The buffer is allocated by caller and the recommended length is 480. The argument value would be copied to the buffer.
			* @param [in] valueBufferLen The length of allocated buffer.
			* @param [in,out] errorMsgBuffer The buffer is allocated by the caller and the recommended length is 256. The error message will be copied to the buffer.
			* @param [in] errorMsgBufferLen The length of the allocated buffer.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
			*
			*/
			int GetModeArgument(const char *pModesName, const int index, const char *pArgumentName, char valueBuffer[], const int valueBufferLen, char errorMsgBuffer[] = NULL, const int errorMsgBufferLen = 0);

			/**
			* Clear template settings.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*
			*/
			int ClearAppendedSettings();

			/**
			* Appends DLRParameter settings in a string to the SDK object.
			*
			* @param [in] content A json string that represents the content of the settings.
			* @param [in, out] errorMsgBuffer The buffer is allocated by caller and the recommended length is 256. The error message will be copied to the bufer.
			* @param [in] errorMsgBufferLen The length of the allocated buffer.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can check errorMsgBuffer to get detailed error message.
			*
			*/
			int AppendSettingsFromString(const char* content, char errorMsgBuffer[]=NULL, const int errorMsgBufferLen=0);

			/**
			* Output DLRParameter settings into a file(JSON file).
			*
			* @param [in] outputFilePath The output file path which stores settings.
			* @param [in] templateName The name of the template which is to be output.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*
			*/
			int OutputSettingsToFile(const char* outputFilePath, const char* templateName);

			/**
			* Recognizes text from memory buffer containing image pixels in defined format.
			*
			* @param [in] pImageDate A struct of DLRImageData that represents an image.
			* @param [in] templateName The template name.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*
			*/
			int RecognizeByBuffer(const DLRImageData* pImageData, const char* templateName);

			/**
			* Recognizes text from a specified image file.
			*
			* @param [in] fileName A string defining the file name.
			* @param [in] templateName The template name.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*
			*/
			int RecognizeByFile(const char* fileName, const char* templateName);

			/**
			* Get all recognized results.
			*
			* @param[in, out] pResults The results are allocated by our SDK and should be freed by calling the function DLR_FreeDLRResults.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		   DLR_GetErrorString() to get detailed error message.
			*
			*/
			int GetAllDLRResults(DLRResultArray** pResults);

			/**
			* Initializes a DM_LTSConnectionParameters struct with default values.
			*
			* @param [in, out] pLTSConnectionParameters The struct of DM_LTSConnectionParameters.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		  DLR_GetErrorString() to get detailed error message. 
			*
			*/
			static int InitLTSConnectionParameters(DM_LTSConnectionParameters *pLTSConnectionParameters);

			/**
			* Initializes the label recognition license and connects to the specified server for online verification.
			*
			* @param [in] pLTSConnectionParameters The struct DM_LTSConnectionParameters with customized settings.
			* @param [in, out] errorMsgBuffer The buffer is allocated by caller and the recommending length is 256. The error message will be copied to the buffer.
			* @param [in] errorMsgBufferLen The length of allocated buffer.
			*
			* @return Returns error code. Returns 0 if the function operates successfully. You can call
			* 		  DLR_GetErrorString() to get detailed error message.
			*
			*/
			static int InitLicenseFromLTS(DM_LTSConnectionParameters *pLTSConnectionParameters, char errorMsgBuffer[] = NULL, const int errorMsgBufferLen = 0);

			/**
			* Free memory allocated for recognized results.
			*
			* @param[in] pResults Recognized results.
			*
			*/
			static void FreeDLRResults(DLRResultArray** pResults);

			int UpdateReferenceRegionFromBarcodeResults(const TextResultArray* barcodeResults, const char * templateName);

		private:
			CLabelRecognition(const CLabelRecognition& r);
			CLabelRecognition& operator=(const CLabelRecognition& r);
		};
	}
}
#endif