/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HOZON"
 * 	found in "HOZON_PRIV_v1.0.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_DiagnosticLogStopReqInfo_H_
#define	_DiagnosticLogStopReqInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DiagnosticLogStopReqInfo */
typedef struct DiagnosticLogStopReqInfo {
	long	 ecuType;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DiagnosticLogStopReqInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DiagnosticLogStopReqInfo;

#ifdef __cplusplus
}
#endif

#endif	/* _DiagnosticLogStopReqInfo_H_ */
#include <asn_internal.h>