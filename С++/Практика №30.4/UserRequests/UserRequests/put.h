#pragma once

#include <iostream>

cpr::Response put() {
	return cpr::Put(cpr::Url("http://httpbin.org/put"));
}