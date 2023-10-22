#include <cstring>
#include <iostream>
#include <filesystem>
void help()
{
	std::cout << std::endl
              << "peti <command>" << std::endl
              << std::endl
              << "Usage:" << std::endl
              << std::endl;
    std::cout << "peti install\t\t"
              << "install all the dependencies in your project" << std::endl;
    std::cout << "peti install <foo>\t"
              << "add the <foo> dependency to your project" << std::endl;
    std::cout << "peti test\t\t"
              << "run this project's tests" << std::endl;
    std::cout << "peti run <foo>\t\t"
              << "run the script named <foo>" << std::endl;
    std::cout << "peti <command> -h\t"
              << "quick help on <command>" << std::endl;
    std::cout << "peti -l\t\t\t"
              << "display usage info for all commands" << std::endl;
    std::cout << "peti help <term>\t"
              << "search for help on <term> (in a browser)" << std::endl;
    std::cout << "peti help peti\t\t"
              << "more involved overview (in a browser)" << std::endl
              << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc < 2 || (strcmpi(argv[1], "help") == 0))
	{
		help();
	}
	
	if (argc > 2)
	{
		if (strcmpi(argv[1],"new") == 0)
		{
			if (strcmpi(argv[2], "") != 0)
			{
				try
				{
					std::string root = argv[2];
					std::string src = root.append("/src");
					std::filesystem::create_directories(src);
					root = argv[2];
					std::string build = root.append("/build");
					std::filesystem::create_directory(build);
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
				}
			}
		}
		// arguments(argv);
	}
	return 0;
}
