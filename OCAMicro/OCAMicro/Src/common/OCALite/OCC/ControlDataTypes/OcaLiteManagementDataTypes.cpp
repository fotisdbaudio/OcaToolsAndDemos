/*  By downloading or using this file, the user agrees to be bound by the terms of the license 
 *  agreement located at http://ocaalliance.com/EULA as an original contracting party.
 */

/*
 *  Description         : OCC management data types.
 *
 */

// ---- Include system wide include files ----

// ---- FileInfo Macro ----

// ---- Include local include files ----
#include "OcaLiteManagementDataTypes.h"

// ---- Helper types and constants ----

// ---- Helper functions ----

// ---- Local data ----

// ---- Function Implementation ----

//lint -save -e1576 Explicit specialization does not occur in the same file as corresponding function template

template <>
void MarshalValue< ::OcaLiteComponent>(const ::OcaLiteComponent& value, ::OcaUint8** destination, const ::IOcaLiteWriter& writer)
{
    MarshalValue< ::OcaUint16>(static_cast< ::OcaUint16>(value), destination, writer);
}

template <>
bool UnmarshalValue< ::OcaLiteComponent>(::OcaLiteComponent& value, ::OcaUint32& bytesLeft, const ::OcaUint8** source, const ::IOcaLiteReader& reader)
{
    ::OcaUint16 component(static_cast< ::OcaUint16>(0));
    bool result(reader.Read(bytesLeft, source, component));
    if (result)
    {
        value = static_cast< ::OcaLiteComponent>(component);
    }

    return result;
}

template <>
::OcaUint32 GetSizeValue< ::OcaLiteComponent>(const ::OcaLiteComponent& value, const ::IOcaLiteWriter& writer)
{
    return GetSizeValue< ::OcaUint16>(static_cast< ::OcaUint16>(value), writer);
}

//lint -restore