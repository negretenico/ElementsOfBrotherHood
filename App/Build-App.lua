project "App"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp", "Source/*.hpp" }

   includedirs
   {
      "Source",
	  -- Include Core
	  "../Core/Source",
      "../Libraries/SFML/include"
   }

   links
   {
      "Core"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
       links
          {
           "../Libraries/SFML/lib/sfml-system-d",
           "../Libraries/SFML/lib/sfml-graphics-d",
           "../Libraries/SFML/lib/sfml-audio-d",
           "../Libraries/SFML/lib/sfml-window-d"
       }

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"
       links
       {
           "../Libraries/SFML/lib/sfml-system",
           "../Libraries/SFML/lib/sfml-graphics",
           "../Libraries/SFML/lib/sfml-audio",
           "../Libraries/SFML/lib/sfml-window"
       }

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
        links
          {
           "../Libraries/SFML/lib/sfml-system",
           "../Libraries/SFML/lib/sfml-graphics",
           "../Libraries/SFML/lib/sfml-audio",
           "../Libraries/SFML/lib/sfml-window"
       }