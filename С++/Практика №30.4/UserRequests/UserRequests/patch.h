#pragma once

#include <iostream>

cpr::Response patch() {
	return cpr::Patch(cpr::Url("http://httpbin.org/patch"));
}