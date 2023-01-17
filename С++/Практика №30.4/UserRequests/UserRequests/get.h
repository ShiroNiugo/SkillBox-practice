#pragma once

#include <iostream>

cpr::Response get() {
	return cpr::Get(cpr::Url("http://httpbin.org/get"));
}
