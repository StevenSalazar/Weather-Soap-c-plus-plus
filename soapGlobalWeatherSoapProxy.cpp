/* soapGlobalWeatherSoapProxy.cpp
   Generated by gSOAP 2.8.21 from meteo.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapGlobalWeatherSoapProxy.h"

GlobalWeatherSoapProxy::GlobalWeatherSoapProxy()
{	GlobalWeatherSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

GlobalWeatherSoapProxy::GlobalWeatherSoapProxy(const struct soap &_soap) : soap(_soap)
{ }

GlobalWeatherSoapProxy::GlobalWeatherSoapProxy(const char *url)
{	GlobalWeatherSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

GlobalWeatherSoapProxy::GlobalWeatherSoapProxy(soap_mode iomode)
{	GlobalWeatherSoapProxy_init(iomode, iomode);
}

GlobalWeatherSoapProxy::GlobalWeatherSoapProxy(const char *url, soap_mode iomode)
{	GlobalWeatherSoapProxy_init(iomode, iomode);
	soap_endpoint = url;
}

GlobalWeatherSoapProxy::GlobalWeatherSoapProxy(soap_mode imode, soap_mode omode)
{	GlobalWeatherSoapProxy_init(imode, omode);
}

GlobalWeatherSoapProxy::~GlobalWeatherSoapProxy()
{ }

void GlobalWeatherSoapProxy::GlobalWeatherSoapProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
	{"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "http://www.webserviceX.NET", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void GlobalWeatherSoapProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void GlobalWeatherSoapProxy::reset()
{	destroy();
	soap_done(this);
	soap_initialize(this);
	GlobalWeatherSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void GlobalWeatherSoapProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *GlobalWeatherSoapProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *GlobalWeatherSoapProxy::soap_fault()
{	return this->fault;
}

const char *GlobalWeatherSoapProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *GlobalWeatherSoapProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int GlobalWeatherSoapProxy::soap_close_socket()
{	return soap_closesock(this);
}

int GlobalWeatherSoapProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void GlobalWeatherSoapProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void GlobalWeatherSoapProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *GlobalWeatherSoapProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int GlobalWeatherSoapProxy::GetWeather(const char *endpoint, const char *soap_action, _ns1__GetWeather *ns1__GetWeather, _ns1__GetWeatherResponse &ns1__GetWeatherResponse)
{	struct soap *soap = this;
	struct __ns1__GetWeather soap_tmp___ns1__GetWeather;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://www.webservicex.net/globalweather.asmx";
	if (soap_action == NULL)
		soap_action = "http://www.webserviceX.NET/GetWeather";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetWeather.ns1__GetWeather = ns1__GetWeather;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetWeather(soap, &soap_tmp___ns1__GetWeather);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetWeather(soap, &soap_tmp___ns1__GetWeather, "-ns1:GetWeather", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetWeather(soap, &soap_tmp___ns1__GetWeather, "-ns1:GetWeather", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__GetWeatherResponse)
		return soap_closesock(soap);
	ns1__GetWeatherResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetWeatherResponse.soap_get(soap, "ns1:GetWeatherResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int GlobalWeatherSoapProxy::GetCitiesByCountry(const char *endpoint, const char *soap_action, _ns1__GetCitiesByCountry *ns1__GetCitiesByCountry, _ns1__GetCitiesByCountryResponse &ns1__GetCitiesByCountryResponse)
{	struct soap *soap = this;
	struct __ns1__GetCitiesByCountry soap_tmp___ns1__GetCitiesByCountry;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://www.webservicex.net/globalweather.asmx";
	if (soap_action == NULL)
		soap_action = "http://www.webserviceX.NET/GetCitiesByCountry";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetCitiesByCountry.ns1__GetCitiesByCountry = ns1__GetCitiesByCountry;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetCitiesByCountry(soap, &soap_tmp___ns1__GetCitiesByCountry);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetCitiesByCountry(soap, &soap_tmp___ns1__GetCitiesByCountry, "-ns1:GetCitiesByCountry", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetCitiesByCountry(soap, &soap_tmp___ns1__GetCitiesByCountry, "-ns1:GetCitiesByCountry", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__GetCitiesByCountryResponse)
		return soap_closesock(soap);
	ns1__GetCitiesByCountryResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetCitiesByCountryResponse.soap_get(soap, "ns1:GetCitiesByCountryResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int GlobalWeatherSoapProxy::GetWeather_(const char *endpoint, const char *soap_action, _ns1__GetWeather *ns1__GetWeather, _ns1__GetWeatherResponse &ns1__GetWeatherResponse)
{	struct soap *soap = this;
	struct __ns1__GetWeather_ soap_tmp___ns1__GetWeather_;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://www.webservicex.net/globalweather.asmx";
	if (soap_action == NULL)
		soap_action = "http://www.webserviceX.NET/GetWeather";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetWeather_.ns1__GetWeather = ns1__GetWeather;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetWeather_(soap, &soap_tmp___ns1__GetWeather_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetWeather_(soap, &soap_tmp___ns1__GetWeather_, "-ns1:GetWeather", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetWeather_(soap, &soap_tmp___ns1__GetWeather_, "-ns1:GetWeather", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__GetWeatherResponse)
		return soap_closesock(soap);
	ns1__GetWeatherResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetWeatherResponse.soap_get(soap, "ns1:GetWeatherResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int GlobalWeatherSoapProxy::GetCitiesByCountry_(const char *endpoint, const char *soap_action, _ns1__GetCitiesByCountry *ns1__GetCitiesByCountry, _ns1__GetCitiesByCountryResponse &ns1__GetCitiesByCountryResponse)
{	struct soap *soap = this;
	struct __ns1__GetCitiesByCountry_ soap_tmp___ns1__GetCitiesByCountry_;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://www.webservicex.net/globalweather.asmx";
	if (soap_action == NULL)
		soap_action = "http://www.webserviceX.NET/GetCitiesByCountry";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetCitiesByCountry_.ns1__GetCitiesByCountry = ns1__GetCitiesByCountry;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetCitiesByCountry_(soap, &soap_tmp___ns1__GetCitiesByCountry_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetCitiesByCountry_(soap, &soap_tmp___ns1__GetCitiesByCountry_, "-ns1:GetCitiesByCountry", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetCitiesByCountry_(soap, &soap_tmp___ns1__GetCitiesByCountry_, "-ns1:GetCitiesByCountry", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__GetCitiesByCountryResponse)
		return soap_closesock(soap);
	ns1__GetCitiesByCountryResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetCitiesByCountryResponse.soap_get(soap, "ns1:GetCitiesByCountryResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */