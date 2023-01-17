#pragma once

#include <iostream>

cpr::Response post() {
	return cpr::Post(cpr::Url("http://httpbin.org/post"));
}