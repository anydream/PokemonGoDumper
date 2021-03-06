#pragma once
#include <stdint.h>
#include <stdlib.h>

// Most comments here are cause of the unity devs and not me.

typedef void*(*Il2CppMethodPointer)(void* target, void* methodinfo);
typedef void*(*InvokerMethod)(/*MethodInfo*/void*, void*, void**);

typedef void* Type_t;

#define FIELD_ATTRIBUTE_STATIC 0x40

#pragma pack(push, p1,4)
typedef struct
{
	int32_t sanity;
	int32_t version;
	int32_t stringLiteralOffset; // string data for managed code
	int32_t stringLiteralCount;
	int32_t stringLiteralDataOffset;
	int32_t stringLiteralDataCount;
	int32_t stringOffset; // string data for metadata
	int32_t stringCount;
	int32_t eventsOffset; // Il2CppEventDefinition
	int32_t eventsCount;
	int32_t propertiesOffset; // Il2CppPropertyDefinition
	int32_t propertiesCount;
	int32_t methodsOffset; // Il2CppMethodDefinition
	int32_t methodsCount;
	int32_t parameterDefaultValuesOffset; // Il2CppParameterDefaultValue
	int32_t parameterDefaultValuesCount;
	int32_t fieldDefaultValuesOffset; // Il2CppFieldDefaultValue
	int32_t fieldDefaultValuesCount;
	int32_t fieldAndParameterDefaultValueDataOffset; // uint8_t
	int32_t fieldAndParameterDefaultValueDataCount;
	int32_t fieldMarshaledSizesOffset; // Il2CppFieldMarshaledSize
	int32_t fieldMarshaledSizesCount;
	int32_t parametersOffset; // Il2CppParameterDefinition
	int32_t parametersCount;
	int32_t fieldsOffset; // Il2CppFieldDefinition
	int32_t fieldsCount;
	int32_t genericParametersOffset; // Il2CppGenericParameter
	int32_t genericParametersCount;
	int32_t genericParameterConstraintsOffset; // TypeIndex
	int32_t genericParameterConstraintsCount;
	int32_t genericContainersOffset; // Il2CppGenericContainer
	int32_t genericContainersCount;
	int32_t nestedTypesOffset; // TypeDefinitionIndex
	int32_t nestedTypesCount;
	int32_t interfacesOffset; // TypeIndex
	int32_t interfacesCount;
	int32_t vtableMethodsOffset; // EncodedMethodIndex
	int32_t vtableMethodsCount;
	int32_t interfaceOffsetsOffset; // Il2CppInterfaceOffsetPair
	int32_t interfaceOffsetsCount;
	int32_t typeDefinitionsOffset; // Il2CppTypeDefinition
	int32_t typeDefinitionsCount;
	int32_t rgctxEntriesOffset; // Il2CppRGCTXDefinition
	int32_t rgctxEntriesCount;
	int32_t imagesOffset; // Il2CppImageDefinition
	int32_t imagesCount;
	int32_t assembliesOffset; // Il2CppAssemblyDefinition
	int32_t assembliesCount;
	int32_t metadataUsageListsOffset; // Il2CppMetadataUsageList
	int32_t metadataUsageListsCount;
	int32_t metadataUsagePairsOffset; // Il2CppMetadataUsagePair
	int32_t metadataUsagePairsCount;
	int32_t fieldRefsOffset; // Il2CppFieldRef
	int32_t fieldRefsCount;
	int32_t referencedAssembliesOffset; // int32_t
	int32_t referencedAssembliesCount;
	int32_t attributesInfoOffset; // Il2CppCustomAttributeTypeRange
	int32_t attributesInfoCount;
	int32_t attributeTypesOffset; // TypeIndex
	int32_t attributeTypesCount;
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)

typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t GuidIndex;

typedef struct
{
	StringIndex nameIndex;
	StringIndex namespaceIndex;
	CustomAttributeIndex customAttributeIndex;
	TypeIndex byvalTypeIndex;
	TypeIndex byrefTypeIndex;

	TypeIndex declaringTypeIndex;
	TypeIndex parentIndex;
	TypeIndex elementTypeIndex; // we can probably remove this one. Only used for enums

	RGCTXIndex rgctxStartIndex;
	int32_t rgctxCount;

	GenericContainerIndex genericContainerIndex;

	MethodIndex delegateWrapperFromManagedToNativeIndex;
	int32_t marshalingFunctionsIndex;
	int32_t ccwFunctionIndex;
	GuidIndex guidIndex;

	uint32_t flags;

	FieldIndex fieldStart;
	MethodIndex methodStart;
	EventIndex eventStart;
	PropertyIndex propertyStart;
	NestedTypeIndex nestedTypesStart;
	InterfacesIndex interfacesStart;
	VTableIndex vtableStart;
	InterfacesIndex interfaceOffsetsStart;

	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;

	// bitfield to portably encode boolean values as single bits
	// 01 - valuetype;
	// 02 - enumtype;
	// 03 - has_finalize;
	// 04 - has_cctor;
	// 05 - is_blittable;
	// 06 - is_import;
	// 07-10 - One of nine possible PackingSize values (0, 1, 2, 4, 8, 16, 32, 64, or 128)
	uint32_t bitfield;
	uint32_t token;
} Il2CppTypeDefinition;

typedef struct
{
	void* unk00;
	void* unk01;
	void* unk02;
	uint32_t uiSize;
	Type_t arr[2];
} TypeArray;

typedef enum 
{
	IL2CPP_TYPE_END = 0x00,       /* End of List */
	IL2CPP_TYPE_VOID = 0x01,
	IL2CPP_TYPE_BOOLEAN = 0x02,
	IL2CPP_TYPE_CHAR = 0x03,
	IL2CPP_TYPE_I1 = 0x04,
	IL2CPP_TYPE_U1 = 0x05,
	IL2CPP_TYPE_I2 = 0x06,
	IL2CPP_TYPE_U2 = 0x07,
	IL2CPP_TYPE_I4 = 0x08,
	IL2CPP_TYPE_U4 = 0x09,
	IL2CPP_TYPE_I8 = 0x0a,
	IL2CPP_TYPE_U8 = 0x0b,
	IL2CPP_TYPE_R4 = 0x0c,
	IL2CPP_TYPE_R8 = 0x0d,
	IL2CPP_TYPE_STRING = 0x0e,
	IL2CPP_TYPE_PTR = 0x0f,       /* arg: <type> token */
	IL2CPP_TYPE_BYREF = 0x10,       /* arg: <type> token */
	IL2CPP_TYPE_VALUETYPE = 0x11,       /* arg: <type> token */
	IL2CPP_TYPE_CLASS = 0x12,       /* arg: <type> token */
	IL2CPP_TYPE_VAR = 0x13,       /* Generic parameter in a generic type definition, represented as number (compressed unsigned integer) number */
	IL2CPP_TYPE_ARRAY = 0x14,       /* type, rank, boundsCount, bound1, loCount, lo1 */
	IL2CPP_TYPE_GENERICINST = 0x15,	   /* <type> <type-arg-count> <type-1> \x{2026} <type-n> */
	IL2CPP_TYPE_TYPEDBYREF = 0x16,
	IL2CPP_TYPE_I = 0x18,
	IL2CPP_TYPE_U = 0x19,
	IL2CPP_TYPE_FNPTR = 0x1b,	      /* arg: full method signature */
	IL2CPP_TYPE_OBJECT = 0x1c,
	IL2CPP_TYPE_SZARRAY = 0x1d,       /* 0-based one-dim-array */
	IL2CPP_TYPE_MVAR = 0x1e,       /* Generic parameter in a generic method definition, represented as number (compressed unsigned integer)  */
	IL2CPP_TYPE_CMOD_REQD = 0x1f,       /* arg: typedef or typeref token */
	IL2CPP_TYPE_CMOD_OPT = 0x20,       /* optional arg: typedef or typref token */
	IL2CPP_TYPE_INTERNAL = 0x21,       /* CLR internal type */

	IL2CPP_TYPE_MODIFIER = 0x40,       /* Or with the following types */
	IL2CPP_TYPE_SENTINEL = 0x41,       /* Sentinel for varargs method signature */
	IL2CPP_TYPE_PINNED = 0x45,       /* Local var that points to pinned object */

	IL2CPP_TYPE_ENUM = 0x55        /* an enumeration */
} Il2CppTypeEnum;

typedef struct
{
	const /*Il2CppType*/void* etype;
	uint8_t rank;
	uint8_t numsizes;
	uint8_t numlobounds;
	int *sizes;
	int *lobounds;
} Il2CppArrayType;

typedef struct
{
	union
	{
		// We have this dummy field first because pre C99 compilers (MSVC) can only initializer the first value in a union.
		void* dummy;
		/*TypeDefinitionIndex*/uint32_t klassIndex; /* for VALUETYPE and CLASS */
		const /*Il2CppType*/void *type;   /* for PTR and SZARRAY */
		Il2CppArrayType *array; /* for ARRAY */
								//MonoMethodSignature *method;
		/*GenericParameterIndex*/uint32_t genericParameterIndex; /* for VAR and MVAR */
		/*Il2CppGenericClass*/void *generic_class; /* for GENERICINST */
	} data;
	unsigned int attrs : 16; /* param attributes or field flags */
	Il2CppTypeEnum type : 8;
	unsigned int num_mods : 6;  /* max 64 modifiers follow at the end */
	unsigned int byref : 1;
	unsigned int pinned : 1;  /* valid when included in a local var signature */
							  //MonoCustomMod modifiers [MONO_ZERO_LEN_ARRAY]; /* this may grow */
} Il2CppType;

typedef struct 
{
	const char* name;
	int32_t position;
	uint32_t token;
	/*CustomAttributeIndex*/uint32_t customAttributeIndex;
	const Il2CppType* parameter_type;
} ParameterInfo;

typedef struct
{
	Il2CppMethodPointer method;
	InvokerMethod invoker_method;
	const char* name;
	/*Il2CppClass*/void *declaring_type;
	const Il2CppType *return_type;
	const ParameterInfo* parameters;

	union
	{
		const /*Il2CppRGCTXData*/void* rgctx_data; /* is_inflated is true and is_generic is false, i.e. a generic instance method */
		const /*Il2CppMethodDefinition*/void* methodDefinition;
	};

	/* note, when is_generic == true and is_inflated == true the method represents an uninflated generic method on an inflated type. */
	union
	{
		const /*Il2CppGenericMethod*/void* genericMethod; /* is_inflated is true */
		const /*Il2CppGenericContainer*/void* genericContainer; /* is_inflated is false and is_generic is true */
	};

	//CustomAttributeIndex customAttributeIndex;
	int customAttributeIndex;
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint8_t parameters_count;
	uint8_t is_generic : 1; /* true if method is a generic method definition */
	uint8_t is_inflated : 1; /* true if declaring_type is a generic instance or if method is a generic instance*/

} MethodInfo;

typedef struct
{
	char* name;
	const Il2CppType* type;
	/*Il2CppClass*/void *parent;
	int32_t offset;	// If offset is -1, then it's thread static
	/*CustomAttributeIndex*/void* customAttributeIndex;
	uint32_t token;
} FieldInfo;


typedef struct
{
	char* szName;
	uint32_t uiAssemblyIndex;
	uint32_t uiTypeStart;
	uint32_t uiTypeCount;
	uint32_t uiEntryPointIndex;
	uint32_t uiNameToClassHashTable; // Probably a pointer?
	uint32_t token;
} Il2CppImage;

typedef struct 
{
	// The following fields are always valid for a Il2CppClass structure
	const Il2CppImage* image;
	void* gc_desc;
	char* name;
	const char* namespaze;
	const Il2CppType* byval_arg;
	const Il2CppType* this_arg;
	/*Il2CppClass*/void* element_class;
	/*Il2CppClass*/void* castClass;
	/*Il2CppClass*/void* declaringType;
	/*Il2CppClass*/void* parent;
	/*Il2CppGenericClass*/void *generic_class;
	const /*Il2CppTypeDefinition*/void* typeDefinition; // non-NULL for Il2CppClass's constructed from type defintions
												// End always valid fields

												// The following fields need initialized before access. This can be done per field or as an aggregate via a call to Class::Init
	FieldInfo* fields; // Initialized in SetupFields
	const /*EventInfo*/void* events; // Initialized in SetupEvents
	const /*PropertyInfo*/void* properties; // Initialized in SetupProperties
	MethodInfo** methods; // Initialized in SetupMethods
	/*Il2CppClass*/void** nestedTypes; // Initialized in SetupNestedTypes
	/*Il2CppClass*/void** implementedInterfaces; // Initialized in SetupInterfaces
	MethodInfo** vtable; // Initialized in Init
	/*Il2CppRuntimeInterfaceOffsetPair*/void* interfaceOffsets; // Initialized in Init
	void* static_fields; // Initialized in Init
	const /*Il2CppRGCTXData*/void* rgctx_data; // Initialized in Init
									   // used for fast parent checks
	/*Il2CppClass*/void** typeHierarchy; // Initialized in SetupTypeHierachy
								 // End initialization required fields
	uint32_t cctor_started;
	uint32_t cctor_finished;
	uint64_t cctor_thread;

	// Remaining fields are always valid except where noted
	/*GenericContainerIndex*/void* genericContainerIndex;
	/*CustomAttributeIndex*/void* customAttributeIndex;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;

	uint16_t method_count; // lazily calculated for arrays, i.e. when rank > 0
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count; // lazily calculated for arrays, i.e. when rank > 0
	uint16_t interfaces_count;
	uint16_t interface_offsets_count; // lazily calculated for arrays, i.e. when rank > 0

	uint8_t typeHierarchyDepth; // Initialized in SetupTypeHierachy
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t packingSize;

	uint8_t valuetype : 1;
	uint8_t initialized : 1;
	uint8_t enumtype : 1;
	uint8_t is_generic : 1;
	uint8_t has_references : 1;
	uint8_t init_pending : 1;
	uint8_t size_inited : 1;
	uint8_t has_finalize : 1;
	uint8_t has_cctor : 1;
	uint8_t is_blittable : 1;
	uint8_t is_import : 1;
} Il2CppClass;

typedef struct 
{
	void* target;
	const MethodInfo* methodInfo;
} VirtualInvokeData;

typedef struct
{
	void *klass; // Il2CppClass
	void *monitor; // MonitorData
} Il2CppObject;

// System.String
typedef struct
{
	Il2CppObject baseclass;

	// System.Int32 System.String::length
	int32_t ___length_0;
	// System.Char System.String::start_char
	uint16_t ___start_char_1;
} String_t;

typedef struct
{
	Il2CppObject baseclass;
	int bounds;
	int max_length;
	void* beginning;
} Il2CppArray;

typedef struct
{
	uint32_t uiImageIndex;
	uint32_t uiCustomAttributeIndex;
	uint32_t uiReferecnedAssemblyStart;
	uint32_t uiRefencedAssemblyCount;
	// Name here
} Il2CppAssembly;

// System.Reflection.Assembly
typedef struct
{
	Il2CppObject baseclass;

	// System.IntPtr System.Reflection.Assembly::_mono_assembly
	Il2CppAssembly* ____mono_assembly_0; // IntPtr_t
	// System.Reflection.Assembly/ResolveEventHolder System.Reflection.Assembly::resolve_event_holder
	void * ___resolve_event_holder_1; // ResolveEventHolder_t2661007650
	// System.Security.Policy.Evidence System.Reflection.Assembly::_evidence
	void * ____evidence_2; // Evidence_t435860
	// System.Security.PermissionSet System.Reflection.Assembly::_minimum
	void * ____minimum_3; // PermissionSet_t20502880
	// System.Security.PermissionSet System.Reflection.Assembly::_optional
	void * ____optional_4; // PermissionSet_t20502880
	// System.Security.PermissionSet System.Reflection.Assembly::_refuse
	void * ____refuse_5; // PermissionSet_t20502880
	// System.Security.PermissionSet System.Reflection.Assembly::_granted
	void * ____granted_6; // PermissionSet_t20502880
	// System.Security.PermissionSet System.Reflection.Assembly::_denied
	void * ____denied_7; // PermissionSet_t20502880
	// System.Boolean System.Reflection.Assembly::fromByteArray
	int ___fromByteArray_8;
	// System.String System.Reflection.Assembly::assemblyName
	String_t* ___assemblyName_9;
} Assembly_t;
