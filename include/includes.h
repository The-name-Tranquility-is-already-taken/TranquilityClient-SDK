#pragma once

#define HTTP_MODE_t "http"
//#define HOSTNAME_t "spookiebois.club"
#define PORT_t "322"


// Config Stuff below plz dont touch.

#ifdef HTTP_MODE_t
#define HTTP_MODE std::string(HTTP_MODE_t)
#endif // DEBUG
#ifndef HTTP_MODE
#define HTTP_MODE std::string("http")
#endif // !HOSTNAME

#ifdef HOSTNAME_t
#define HOSTNAME std::string(HOSTNAME_t)
#endif // HOSTNAME_t
#ifndef HOSTNAME
#define HOSTNAME std::string("localhost")
#endif // !HOSTNAME

#ifdef PORT_t
#define PORT std::string(PORT_t)
#endif // PORT_t
#ifndef PORT
#define PORT "322"
#endif // !PORT

#define WEB_ROOT HTTP_MODE + std::string ("://") + HOSTNAME + std::string(":") + PORT