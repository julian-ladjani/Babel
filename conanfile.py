from conans import ConanFile, CMake

class Conan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "portaudio/v190600.20161030@bincrafters/stable", \
              "opus/1.2.1@bincrafters/stable",\
              "boost/1.67.0@conan/stable",\
              "Qt/5.11.2@bincrafters/stable"

   generators = "cmake", "cmake_find_package", "cmake_paths"
   def configure(self):
       self.options["Qt"].shared = True
       if self.settings.os == "Windows":
           self.options["portaudio"].shared = True
       if "shared" in self.options:
           pass

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin") # From bin to bin

   def build(self):
       cmake = CMake(self)
       cmake.configure(source_folder="")
       cmake.build()
