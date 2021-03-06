#include "pe/pe_generator.h"

PIMAGE_DOS_HEADER pe_generator::build_dos_header()
{
	constexpr auto DOS_HEADER_SIZE = sizeof IMAGE_DOS_HEADER;

	dos_header.e_magic = 'MZ';
	dos_header.e_lfanew = 0x40;

	return &dos_header;
}

PIMAGE_FILE_HEADER pe_generator::build_coff_header()
{
	constexpr auto COFF_HEADER_SIZE = sizeof IMAGE_FILE_HEADER;

	coff_header.Machine = IMAGE_FILE_MACHINE_AMD64;
	coff_header.NumberOfSections = 3; // TODO
	coff_header.TimeDateStamp = 0; // 1970-01-01 00:00:00
	coff_header.PointerToSymbolTable = 0;
	coff_header.NumberOfSymbols = 0;
	coff_header.SizeOfOptionalHeader = 0; // TODO
	coff_header.Characteristics = IMAGE_FILE_EXECUTABLE_IMAGE | IMAGE_FILE_LARGE_ADDRESS_AWARE;

	return &coff_header;
}

PIMAGE_OPTIONAL_HEADER pe_generator::build_optional_header(
	const uint64_t image_base, const int section_alignment, const int file_alignment,
	const uint64_t sr, uint64_t sc, const uint64_t hr, const uint64_t hc
)
{
	constexpr auto OPTIONAL_HEADER_SIZE = sizeof IMAGE_OPTIONAL_HEADER;

	optional_header.Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
	optional_header.MajorLinkerVersion = 0xE;
	optional_header.MinorLinkerVersion = 0x1C;
	optional_header.SizeOfCode = 0; // TODO
	optional_header.SizeOfInitializedData = 0; // TODO
	optional_header.AddressOfEntryPoint = 0; // TODO
	optional_header.BaseOfCode = 1000;

	optional_header.ImageBase = image_base;
	optional_header.SectionAlignment = section_alignment;
	optional_header.FileAlignment = file_alignment;
	optional_header.MajorOperatingSystemVersion = 5;
	optional_header.MinorOperatingSystemVersion = 3;
	optional_header.MajorImageVersion = 0;
	optional_header.MinorImageVersion = 0;
	optional_header.MajorSubsystemVersion = 5;
	optional_header.MinorSubsystemVersion = 3;
	optional_header.Win32VersionValue = 0;
	optional_header.SizeOfImage = 0; // TODO
	optional_header.CheckSum = 0;
	optional_header.Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
	optional_header.DllCharacteristics = IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE | IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY |
		IMAGE_DLLCHARACTERISTICS_NX_COMPAT | IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE;
	optional_header.SizeOfStackReserve = sr;
	optional_header.SizeOfStackCommit = sc;
	optional_header.SizeOfHeapReserve = hr;
	optional_header.SizeOfHeapCommit = hc;
	optional_header.LoaderFlags = 0;
	optional_header.NumberOfRvaAndSizes = 10;

	return &optional_header;
}

void pe_generator::add_section(const PIMAGE_SECTION_HEADER section_header)
{
	section_headers.push_back(*section_header);
}

void pe_generator::add_section(const IMAGE_SECTION_HEADER section_header)
{
	section_headers.push_back(section_header);
}