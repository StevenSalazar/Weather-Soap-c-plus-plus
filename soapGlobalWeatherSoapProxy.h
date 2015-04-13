/* soapGlobalWeatherSoapProxy.h
   Generated by gSOAP 2.8.21 from meteo.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapGlobalWeatherSoapProxy_H
#define soapGlobalWeatherSoapProxy_H
#include "soapH.h"

class SOAP_CMAC GlobalWeatherSoapProxy : public soap
{ public:
	/// Endpoint URL of service 'GlobalWeatherSoapProxy' (change as needed)
	const char *soap_endpoint;
	/// Variables globally declared in meteo.h (non-static)
	/// Constructor
	GlobalWeatherSoapProxy();
	/// Construct from another engine state
	GlobalWeatherSoapProxy(const struct soap&);
	/// Constructor with endpoint URL
	GlobalWeatherSoapProxy(const char *url);
	/// Constructor with engine input+output mode control
	GlobalWeatherSoapProxy(soap_mode iomode);
	/// Constructor with URL and input+output mode control
	GlobalWeatherSoapProxy(const char *url, soap_mode iomode);
	/// Constructor with engine input and output mode control
	GlobalWeatherSoapProxy(soap_mode imode, soap_mode omode);
	/// Destructor frees deserialized data
	virtual	~GlobalWeatherSoapProxy();
	/// Initializer used by constructors
	virtual	void GlobalWeatherSoapProxy_init(soap_mode imode, soap_mode omode);
	/// Delete all deserialized data (with soap_destroy and soap_end)
	virtual	void destroy();
	/// Delete all deserialized data and reset to default
	virtual	void reset();
	/// Disables and removes SOAP Header from message
	virtual	void soap_noheader();
	/// Get SOAP Header structure (NULL when absent)
	virtual	const SOAP_ENV__Header *soap_header();
	/// Get SOAP Fault structure (NULL when absent)
	virtual	const SOAP_ENV__Fault *soap_fault();
	/// Get SOAP Fault string (NULL when absent)
	virtual	const char *soap_fault_string();
	/// Get SOAP Fault detail as string (NULL when absent)
	virtual	const char *soap_fault_detail();
	/// Close connection (normally automatic, except for send_X ops)
	virtual	int soap_close_socket();
	/// Force close connection (can kill a thread blocked on IO)
	virtual	int soap_force_close_socket();
	/// Print fault
	virtual	void soap_print_fault(FILE*);
#ifndef WITH_LEAN
	/// Print fault to stream
#ifndef WITH_COMPAT
	virtual	void soap_stream_fault(std::ostream&);
#endif

	/// Put fault into buffer
	virtual	char *soap_sprint_fault(char *buf, size_t len);
#endif

	/// Web service operation 'GetWeather' (returns error code or SOAP_OK)
	virtual	int GetWeather(_ns1__GetWeather *ns1__GetWeather, _ns1__GetWeatherResponse &ns1__GetWeatherResponse) { return this->GetWeather(NULL, NULL, ns1__GetWeather, ns1__GetWeatherResponse); }
	virtual	int GetWeather(const char *endpoint, const char *soap_action, _ns1__GetWeather *ns1__GetWeather, _ns1__GetWeatherResponse &ns1__GetWeatherResponse);

	/// Web service operation 'GetCitiesByCountry' (returns error code or SOAP_OK)
	virtual	int GetCitiesByCountry(_ns1__GetCitiesByCountry *ns1__GetCitiesByCountry, _ns1__GetCitiesByCountryResponse &ns1__GetCitiesByCountryResponse) { return this->GetCitiesByCountry(NULL, NULL, ns1__GetCitiesByCountry, ns1__GetCitiesByCountryResponse); }
	virtual	int GetCitiesByCountry(const char *endpoint, const char *soap_action, _ns1__GetCitiesByCountry *ns1__GetCitiesByCountry, _ns1__GetCitiesByCountryResponse &ns1__GetCitiesByCountryResponse);

	/// Web service operation 'GetWeather' (returns error code or SOAP_OK)
	virtual	int GetWeather_(_ns1__GetWeather *ns1__GetWeather, _ns1__GetWeatherResponse &ns1__GetWeatherResponse) { return this->GetWeather_(NULL, NULL, ns1__GetWeather, ns1__GetWeatherResponse); }
	virtual	int GetWeather_(const char *endpoint, const char *soap_action, _ns1__GetWeather *ns1__GetWeather, _ns1__GetWeatherResponse &ns1__GetWeatherResponse);

	/// Web service operation 'GetCitiesByCountry' (returns error code or SOAP_OK)
	virtual	int GetCitiesByCountry_(_ns1__GetCitiesByCountry *ns1__GetCitiesByCountry, _ns1__GetCitiesByCountryResponse &ns1__GetCitiesByCountryResponse) { return this->GetCitiesByCountry_(NULL, NULL, ns1__GetCitiesByCountry, ns1__GetCitiesByCountryResponse); }
	virtual	int GetCitiesByCountry_(const char *endpoint, const char *soap_action, _ns1__GetCitiesByCountry *ns1__GetCitiesByCountry, _ns1__GetCitiesByCountryResponse &ns1__GetCitiesByCountryResponse);
};
#endif