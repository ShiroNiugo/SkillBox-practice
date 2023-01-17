#pragma once

#include <iostream>

cpr::Response del() {
	return cpr::Delete(cpr::Url("http://httpbin.org/delete"));
}