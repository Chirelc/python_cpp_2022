#include <pybind11/pybind11.h>

struct Version {
std::string version;
Version(const std::string &version) : version(version) { }
void setVersion(const std::string &version_) { version = version_; }
const std::string  &getVersion()const {
 return version;
}

/*char const* greet() {
  return "hello, world";
}*/
};
namespace py = pybind11;


PYBIND11_MODULE(hello_component,m)
{
py::class_<Version>(m, "Version")
	.def(py::init<const std::string &>())  
	.def("setVersion", &Version::setVersion)
        .def("getVersion", &Version::getVersion);
	/*def(great,&great,a function saying hello);*/
}
