import os
import re

# Define paths
INCLUDE_DIR = 'include'
MOCK_LIBRARY_DIR = 'mock_library'
MOCK_INCLUDE_DIR = os.path.join(MOCK_LIBRARY_DIR, 'include')
MOCK_SRC_DIR = os.path.join(MOCK_LIBRARY_DIR, 'src')

# Ensure mock directories exist
os.makedirs(MOCK_INCLUDE_DIR, exist_ok=True)
os.makedirs(MOCK_SRC_DIR, exist_ok=True)

# List of qcap headers to process (excluding qcap.h.bak and qcap.h which will be central)
# Filtered headers for module-specific mocks
qcap_headers_to_mock = [f for f in os.listdir(INCLUDE_DIR) 
                        if f.startswith('qcap.') and f.endswith('.h') 
                        and not f.endswith('.h.bak') 
                        and f not in ['qcap.h', 'qcap.types.h', 'qcap.callbacks.h', 'qcap.common.h', 'qcap.windef.h', 'qcap.linux.h', 'qcap.h2.h']]

# Read content of special headers for centralized typedefs/defines
qcap_types_h_content = ""
if os.path.exists(os.path.join(INCLUDE_DIR, 'qcap.types.h')):
    with open(os.path.join(INCLUDE_DIR, 'qcap.types.h'), 'r') as f:
        qcap_types_h_content = f.read()

qcap_callbacks_h_content = ""
if os.path.exists(os.path.join(INCLUDE_DIR, 'qcap.callbacks.h')):
    with open(os.path.join(INCLUDE_DIR, 'qcap.callbacks.h'), 'r') as f:
        qcap_callbacks_h_content = f.read()

qcap_common_h_content = ""
if os.path.exists(os.path.join(INCLUDE_DIR, 'qcap.common.h')):
    with open(os.path.join(INCLUDE_DIR, 'qcap.common.h'), 'r') as f:
        qcap_common_h_content = f.read()

qcap_windef_h_content = ""
if os.path.exists(os.path.join(INCLUDE_DIR, 'qcap.windef.h')):
    with open(os.path.join(INCLUDE_DIR, 'qcap.windef.h'), 'r') as f:
        qcap_windef_h_content = f.read()

qcap_h2_h_content = ""
if os.path.exists(os.path.join(INCLUDE_DIR, 'qcap.h2.h')):
    with open(os.path.join(INCLUDE_DIR, 'qcap.h2.h'), 'r') as f:
        qcap_h2_h_content = f.read()

# Common mock definitions template
COMMON_MOCK_DEFINITIONS_H_TEMPLATE = """
#pragma once

#include <cstddef> // For size_t, nullptr
#include <cstdint> // For intptr_t, uintptr_t
#include <cstdio>  // For fprintf, stderr

// Define QCAP_EXT_API and QCAP_EXPORT for mocking
#ifndef QCAP_EXT_API
#define QCAP_EXT_API
#endif

#ifndef QCAP_EXPORT
#define QCAP_EXPORT
#endif

// Define DEFVAL macro for C++ compatibility
#ifndef DEFVAL
#ifdef __cplusplus
#define DEFVAL(value) = value
#else
#define DEFVAL(value)
#endif
#endif

// Dummy QRESULT definition for mocking. QRETURN will be taken from qcap.types.h
// typedef int QRESULT; // Removed here, will be parsed from qcap.types.h or similar if exists.
#define QCAP_RS_SUCCESSFUL 0
#define QCAP_RS_FAILED 1

// Dummy WSTRING and PVOID definitions
#ifndef WSTRING
typedef wchar_t* WSTRING;
#endif

#ifndef PVOID
typedef void* PVOID;
#endif

// Dummy HWND definition
#ifndef HWND
typedef void* HWND; // Mock HWND as a void pointer
#endif

// Add other common types if necessary, e.g., ULONG, ULONGLONG, DWORD
#ifndef ULONG
typedef unsigned long ULONG;
#endif

#ifndef ULONGLONG
typedef unsigned long long ULONGLONG;
#endif

#ifndef DWORD
typedef unsigned long DWORD;
#endif

#ifndef BOOL
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#endif

#ifndef CHAR
typedef char CHAR;
#endif

#ifndef BYTE
typedef unsigned char BYTE;
#endif

#ifndef UINT
typedef unsigned int UINT;
#endif

#ifndef INT
typedef int INT;
#endif

#ifndef LONG
typedef long LONG;
#endif

// Mock missing constants/enum members found during compilation
#ifndef BASELINE
#define BASELINE 0
#endif

#ifndef CAVLC
#define CAVLC 0
#endif

#ifndef QCAP_ENUM_TYPE_DEVICE_NAME
#define QCAP_ENUM_TYPE_DEVICE_NAME 0
#endif

#ifndef QCAP_CUDAHOST_ALLOC_MAPPED
#define QCAP_CUDAHOST_ALLOC_MAPPED 0
#endif

#ifndef QCAP_STRING_ALIGNMENT_STYLE_LEFT
#define QCAP_STRING_ALIGNMENT_STYLE_LEFT 0
#endif

#ifndef QCAP_SEQUENCE_STYLE_FOREMOST
#define QCAP_SEQUENCE_STYLE_FOREMOST 0
#endif

#ifndef QCAP_RECORD_FLAG_FULL
#define QCAP_RECORD_FLAG_FULL 0
#endif

#ifndef QCAP_3D_STEREO_BUFFER_SIDE_BY_SIDE
#define QCAP_3D_STEREO_BUFFER_SIDE_BY_SIDE 0
#endif

#ifndef QCAP_SCALE_STYLE_STRETCH
#define QCAP_SCALE_STYLE_STRETCH 0
#endif

#ifndef QCAP_SIP_TRANSPORT_PROTOCOL_UDP
#define QCAP_SIP_TRANSPORT_PROTOCOL_UDP 0
#endif

#ifndef QCAP_DECODER_TYPE_SOFTWARE
#define QCAP_DECODER_TYPE_SOFTWARE 0
#endif

#ifndef QCAP_FILE_TIMEUNIT_FRAME
#define QCAP_FILE_TIMEUNIT_FRAME 0
#endif

#ifndef QCAP_HL7_VERSION_24
#define QCAP_HL7_VERSION_24 0
#endif

#ifndef QCAP_ANIMATION_CLIP_MIRROR_TYPE_NONE
#define QCAP_ANIMATION_CLIP_MIRROR_TYPE_NONE 0
#endif

#ifndef QCAP_COLORSPACE_TYPE_ABGR32
#define QCAP_COLORSPACE_TYPE_ABGR32 0
#endif

#ifndef QCAP_3D_STEREO_DISPLAY_MODE_LINE_BY_LINE
#define QCAP_3D_STEREO_DISPLAY_MODE_LINE_BY_LINE 0
#endif

#ifndef QCAP_SERIAL_PORT_PARITY_CHECK_NONE
#define QCAP_SERIAL_PORT_PARITY_CHECK_NONE 0
#endif

#ifndef QCAP_SERIAL_PORT_STOP_BITS_ONE
#define QCAP_SERIAL_PORT_STOP_BITS_ONE 0
#endif

#ifndef QCAP_SERIAL_PORT_FLOW_CONTROL_NONE
#define QCAP_SERIAL_PORT_FLOW_CONTROL_NONE 0
#endif

#ifndef QCAP_COLORRANGE_TYPE_FULL
#define QCAP_COLORRANGE_TYPE_FULL 0
#endif

// Windows specific types mocking (from qcap.windef.h)
#ifndef ULONG_PTR
typedef unsigned long ULONG_PTR;
#endif
#ifndef DWORD_PTR
typedef unsigned long DWORD_PTR;
#endif
#ifndef _W64
#define _W64
#endif
#ifndef WORD
typedef unsigned short WORD;
#endif
#ifndef CRITICAL_SECTION
typedef void* CRITICAL_SECTION; // Mock as void*
#endif
#ifndef VOID
#define VOID void
#endif

// Mock for complex structs that might cause issues, simplifying them
// These are often found in qcap.windef.h
#ifndef BITMAPFILEHEADER_DEFINED
#define BITMAPFILEHEADER_DEFINED
typedef struct tagBITMAPFILEHEADER {
  WORD    bfType;
  DWORD   bfSize;
  WORD    bfReserved1;
  WORD    bfReserved2;
  DWORD   bfOffBits;
} BITMAPFILEHEADER;
#endif

#ifndef BITMAPINFOHEADER_DEFINED
#define BITMAPINFOHEADER_DEFINED
typedef struct tagBITMAPINFOHEADER {
  DWORD  biSize;
  LONG   biWidth;
  LONG   biHeight;
  WORD   biPlanes;
  WORD   biBitCount;
  DWORD  biCompression;
  DWORD  biSizeImage;
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER;
#endif

// Mock for complex types from qcap.hi3531a.h
#ifndef qcap_generic_av_frame_t
typedef struct qcap_generic_av_frame_t {
    // Simplified structure for mocking
    PVOID  pData[4];
    int    iLineSize[4];
    int    iWidth;
    int    iHeight;
    int    iFormat;
    long long  llPTS;
} qcap_generic_av_frame_t;
#endif

#ifndef PBYTE
typedef unsigned char* PBYTE;
#endif

#ifndef QCAP_PROPERTY_MCU_VERSION_RESPONSE
typedef struct QCAP_PROPERTY_MCU_VERSION_RESPONSE_mock {} QCAP_PROPERTY_MCU_VERSION_RESPONSE;
#endif
#ifndef QCAP_PROPERTY_SC632N8_MCU_VERSION_RESPONSE
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC632N8_MCU_VERSION_RESPONSE;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4HDMI_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4SDI_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4_MCU_VERSION_RESPONSE
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4_MCU_VERSION_RESPONSE;
#endif
#ifndef QCAP_PROPERTY_SC6D0N8_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N8_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_LED_IN
typedef struct QCAP_PROPERTY_SC6D0N4HDMI_LED_IN_mock {} QCAP_PROPERTY_SC6D0N4HDMI_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMIQL_LED_IN
typedef QCAP_PROPERTY_SC6D0N4HDMI_LED_IN QCAP_PROPERTY_SC6D0N4HDMIQL_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMIQL_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4HDMIQL_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_VOLUME_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_VOLUME_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_BACKLIGHT_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_BACKLIGHT_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT
typedef struct QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT_mock {} QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI40_BUTTON_OUT
typedef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT QCAP_PROPERTY_SC6D0N4HDMI40_BUTTON_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_OUT
typedef QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDI_LED_IN
typedef struct QCAP_PROPERTY_SC6D0N4SDI_LED_IN_mock {} QCAP_PROPERTY_SC6D0N4SDI_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI40_LED_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_LED_IN QCAP_PROPERTY_SC6D0N4HDMI40_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI_LED_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_LED_IN QCAP_PROPERTY_SC6D0N4HDMI_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDIQL_LED_IN
typedef QCAP_PROPERTY_SC6D0N4SDI_LED_IN QCAP_PROPERTY_SC6D0N4SDIQL_LED_IN;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4HDMI40_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4HDMI40_MCU_VERSION_OUT;
#endif
#ifndef QCAP_PROPERTY_SC6D0N4SDIQL_MCU_VERSION_OUT
typedef QCAP_PROPERTY_MCU_VERSION_RESPONSE QCAP_PROPERTY_SC6D0N4SDIQL_MCU_VERSION_OUT;
#endif
"""

# Store all typedefs collected from original headers to put into qcap_mock_common.h
all_collected_typedefs = set()

# Regex to find typedefs (structs, enums, function pointers)
# The regex attempts to capture full typedefs.
# We explicitly exclude QRESULT and QRETURN for now as they are handled.
# This pattern tries to be comprehensive but might need adjustments for edge cases.
typedef_pattern_strong = re.compile(
    r'(typedef\s+(?:struct|enum|union)\s*(?:[a-zA-Z_][a-zA-Z0-9_]*)\s*\{[^{}]*?\}(?:\s*[a-zA-Z_][a-zA-Z0-9_]*)*\s*;)|' # Named Struct/enum/union
    r'(typedef\s+(?:struct|enum|union)\s*\{[^{}]*?\}(?:\s*[a-zA-Z_][a-zA-Z0-9_]*)*\s*;)|' # Anonymous Struct/enum/union followed by name
    r'(typedef\s+(?!int\s+QRETURN\b)(?!int\s+QRESULT\b)(?:[a-zA-Z_][a-zA-Z0-9_]*\s+)+\*?[a-zA-Z_][a-zA-Z0-9_]*\s*;)|' # Simple typedefs, excluding QRETURN/QRESULT
    r'(typedef\s+(?:QRETURN|QRESULT)\s+\(QCAP_EXPORT\s+\*[a-zA-Z_][a-zA-Z0-9_]*\)\s*\(.*?\)\s*;)', # Function pointer typedefs
    re.DOTALL
)

# Function to extract typedefs from content
def extract_typedefs(content_str):
    found_typedefs = set()
    # Temporarily remove comments to simplify regex matching
    temp_content_no_comments = re.sub(r'/\*.*?\*/', '', content_str, flags=re.DOTALL)
    temp_content_no_comments = re.sub(r'//.*', '', temp_content_no_comments)

    for match in typedef_pattern_strong.finditer(temp_content_no_comments):
        typedef_text = match.group(0).strip()
        # Filter out common types already defined or complex Windows types that are mocked explicitly
        if any(keyword in typedef_text for keyword in [
            "ULONG_PTR", "DWORD_PTR", "_W64", "WORD", "CRITICAL_SECTION", "VOID",
            "tagBITMAPFILEHEADER", "tagBITMAPINFOHEADER",
            "qcap_generic_av_frame_t", "PBYTE",
            "QCAP_PROPERTY_MCU_VERSION_RESPONSE", "QCAP_PROPERTY_SC632N8_MCU_VERSION_RESPONSE",
            "QCAP_PROPERTY_SC6D0N4HDMI_MCU_VERSION_OUT", "QCAP_PROPERTY_SC6D0N4SDI_MCU_VERSION_OUT",
            "QCAP_PROPERTY_SC6D0N4_MCU_VERSION_RESPONSE", "QCAP_PROPERTY_SC6D0N8_MCU_VERSION_OUT",
            "QCAP_PROPERTY_SC6D0N4HDMI_LED_IN", "QCAP_PROPERTY_SC6D0N4HDMIQL_LED_IN",
            "QCAP_PROPERTY_SC6D0N4HDMIQL_MCU_VERSION_OUT", "QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_IN",
            "QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_IN", "QCAP_PROPERTY_SC6D0N4SDI_AUDIO_MIXER_VOLUME_IN",
            "QCAP_PROPERTY_SC6D0N4HDMI_AUDIO_MIXER_VOLUME_IN", "QCAP_PROPERTY_SC6D0N4SDI_BUTTON_BACKLIGHT_IN",
            "QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_BACKLIGHT_IN", "QCAP_PROPERTY_SC6D0N4SDI_BUTTON_OUT",
            "QCAP_PROPERTY_SC6D0N4HDMI40_BUTTON_OUT", "QCAP_PROPERTY_SC6D0N4HDMI_BUTTON_OUT",
            "QCAP_PROPERTY_SC6D0N4SDI_LED_IN", "QCAP_PROPERTY_SC6D0N4HDMI40_LED_IN",
            "QCAP_PROPERTY_SC6D0N4HDMI_LED_IN", "QCAP_PROPERTY_SC6D0N4SDIQL_LED_IN",
            "QCAP_PROPERTY_SC6D0N4HDMI40_MCU_VERSION_OUT", "QCAP_PROPERTY_SC6D0N4SDIQL_MCU_VERSION_OUT"
        ]):
            continue
        found_typedefs.add(typedef_text)
    return found_typedefs

# Collect typedefs from relevant headers
for h_file in ['qcap.types.h', 'qcap.callbacks.h', 'qcap.common.h', 'qcap.windef.h', 'qcap.h2.h']:
    file_path = os.path.join(INCLUDE_DIR, h_file)
    if os.path.exists(file_path):
        with open(file_path, 'r') as f:
            content = f.read()
            all_collected_typedefs.update(extract_typedefs(content))

# Add collected typedefs to the common mock definitions template
typedefs_for_common_header = sorted(list(all_collected_typedefs))
COMMON_MOCK_DEFINITIONS_H_FINAL = COMMON_MOCK_DEFINITIONS_H_TEMPLATE + "\n// Collected Typedefs from original headers\n"
for td in typedefs_for_common_header:
    COMMON_MOCK_DEFINITIONS_H_FINAL += f"{td}\n"

# Write common mock definitions to a single header file
with open(os.path.join(MOCK_INCLUDE_DIR, 'qcap_mock_common.h'), 'w') as f:
    f.write(COMMON_MOCK_DEFINITIONS_H_FINAL)

# Regex to find function declarations
function_pattern = re.compile(
    r'(?:QCAP_EXT_API\s+)?(QRESULT)\s+(?:QCAP_EXPORT\s+)?([a-zA-Z_][a-zA-Z0-9_]*)\s*\((.*?)\);',
    re.DOTALL
)

# Main qcap.h content to be used for the central mock header
main_qcap_h_includes = []

# Process each qcap header
for header_file in qcap_headers_to_mock:
    original_path = os.path.join(INCLUDE_DIR, header_file)
    module_name = header_file.replace('qcap.', '').replace('.h', '')
    mock_header_name = f'mock_qcap_{module_name}.h'
    mock_source_name = f'mock_qcap_{module_name}.cpp'
    mock_header_path = os.path.join(MOCK_INCLUDE_DIR, mock_header_name)
    mock_source_path = os.path.join(MOCK_SRC_DIR, mock_source_name)

    print(f"Processing {header_file}...")

    with open(original_path, 'r') as f:
        content = f.read()

    mock_header_lines = []
    mock_source_lines = []
    function_declarations = []

    # Add include guards and common mock definitions
    mock_header_lines.append(f"#ifndef MOCK_QCAP_{module_name.upper()}_H\n")
    mock_header_lines.append(f"#define MOCK_QCAP_{module_name.upper()}_H\n\n")
    mock_header_lines.append("#include \"qcap_mock_common.h\"\n")
    
    mock_header_lines.append("\n#ifdef __cplusplus\nextern \"C\"\n{\n#endif\n")

    current_processed_content = content

    # Extract function declarations
    for match in function_pattern.finditer(current_processed_content):
        return_type = match.group(1).strip()
        func_name = match.group(2).strip()
        params_str = match.group(3).strip()

        # For mock headers, we keep the DEFVAL in C++ for proper declarations
        mock_header_func_declaration = f"QCAP_EXT_API {return_type} QCAP_EXPORT {func_name}({params_str});"
        
        # For mock source, we need to remove DEFVAL for definition
        # Also remove /*IN*/ /*OUT*/ for parameter names extraction
        params_for_source_definition_clean = re.sub(r'/\*IN\*/|/\*OUT\*/', '', params_str)
        params_for_source_definition_clean = re.sub(r'DEFVAL\s*\(.*?\)', '', params_for_source_definition_clean)
        
        # Extract parameter names for logging and unused parameter casting
        param_names_for_unused_cast = []
        param_list = []
        
        # Split parameters by comma, handling potential commas inside parentheses (e.g., function pointers)
        paren_level = 0
        current_param_part = []
        for char in params_for_source_definition_clean:
            if char == '(':
                paren_level += 1
            elif char == ')':
                paren_level -= 1
            elif char == ',' and paren_level == 0:
                param_list.append("".join(current_param_part).strip())
                current_param_part = []
                continue
            current_param_part.append(char)
        if current_param_part: # Add the last parameter
            param_list.append("".join(current_param_part).strip())

        for param in param_list:
            if param:
                # Find the last word in the parameter string, which should be the name
                name_match = re.search(r'\b([a-zA-Z_][a-zA-Z0-9_]*)(?:\s*\[.*?\])?\s*$', param) # handle array parameters
                if name_match:
                    param_names_for_unused_cast.append(name_match.group(1))
                elif '*' in param: # Handle pointer parameters if name not found by previous regex
                    name_match = re.search(r'\*\s*([a-zA-Z_][a-zA-Z0-9_]*)\s*$', param)
                    if name_match:
                        param_names_for_unused_cast.append(name_match.group(1))

        function_declarations.append({
            'return_type': return_type,
            'func_name': func_name,
            'mock_header_declaration': mock_header_func_declaration,
            'params_for_source_definition_raw': params_str, # Original params for C++ definition in header
            'params_for_source_definition_clean': params_for_source_definition_clean, # Cleaned for C++ definition
            'param_names_for_logging': ', '.join(param_names_for_unused_cast),
            'param_names_for_unused_cast': param_names_for_unused_cast
        })
    
    # Add function declarations to mock header
    mock_header_lines.append("\n// Function Declarations\n")
    for func in function_declarations:
        mock_header_lines.append(f"{func['mock_header_declaration']}\n")

    mock_header_lines.append("\n#ifdef __cplusplus\n}\n#endif\n")
    mock_header_lines.append(f"\n#endif // MOCK_QCAP_{module_name.upper()}_H\n")

    # Write mock header
    with open(mock_header_path, 'w') as f:
        f.write("".join(mock_header_lines))

    # Generate mock source file
    mock_source_lines.append(f'#include "{mock_header_name}"\n')
    mock_source_lines.append(f'#include <cstdio> // For fprintf, stderr\n\n')

    for func in function_declarations:
        return_type = func['return_type']
        func_name = func['func_name']
        params_str_for_source_definition_raw = func['params_for_source_definition_raw']
        param_names_for_logging = func['param_names_for_logging']
        param_names_for_unused_cast = func['param_names_for_unused_cast']

        # Remove DEFVAL from the definition in the .cpp file
        final_params_for_source_definition = re.sub(r'DEFVAL\s*\(.*?\)', '', params_str_for_source_definition_raw)
        
        # Remove /*IN*/ and /*OUT*/ from the definition parameters
        final_params_for_source_definition = re.sub(r'/\*IN\*/|/\*OUT\*/', '', final_params_for_source_definition)


        mock_source_lines.append(f"QCAP_EXT_API {return_type} QCAP_EXPORT {func_name}({final_params_for_source_definition})\n{{\n")
        
        # Add (void) casts for unused parameters
        for param_name in param_names_for_unused_cast:
            mock_source_lines.append(f"    (void){param_name};\n")

        mock_source_lines.append(f'    fprintf(stderr, "Mock function called: {func_name}(%s)\\n", "{param_names_for_logging}");\n')

        # Add dummy return value based on return_type
        if return_type == 'QRESULT':
            mock_source_lines.append(f"    return QCAP_RS_SUCCESSFUL;\n")
        elif return_type == 'PVOID' or return_type.endswith('*'):
            mock_source_lines.append(f"    return nullptr;\n")
        elif return_type == 'WSTRING':
            mock_source_lines.append(f"    return nullptr;\n")
        elif return_type == 'HWND':
            mock_source_lines.append(f"    return nullptr;\n")
        elif return_type == 'BOOL':
            mock_source_lines.append(f"    return FALSE;\n")
        elif return_type in ['CHAR', 'BYTE', 'UINT', 'INT', 'LONG', 'ULONG', 'ULONGLONG', 'DWORD']:
            mock_source_lines.append(f"    return 0;\n")
        elif return_type == 'double':
            mock_source_lines.append(f"    return 0.0;\n")
        else:
            mock_source_lines.append(f"    return ({return_type})0;\n") # Cast to return type


        mock_source_lines.append(f"}}\n\n")

    # Write mock source
    with open(mock_source_path, 'w') as f:
        f.write("".join(mock_source_lines))

    main_qcap_h_includes.append(f'#include "{mock_header_name}"\n')

# Create the central mock_qcap.h that includes all modular mock headers
with open(os.path.join(MOCK_INCLUDE_DIR, 'mock_qcap.h'), 'w') as f:
    f.write("#pragma once\n\n")
    f.write("#include \"qcap_mock_common.h\"\n")
    for include_line in main_qcap_h_includes:
        f.write(include_line)
    f.write("\n")

print("Mock library generation complete.")
