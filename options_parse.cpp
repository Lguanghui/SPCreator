// authorName (c) 2023, Guanghui Liang. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Created by Guanghui Liang on 2023/11/16.
//

#include "options_parse.h"
#include <iostream>

ProgramOptions ParseOptions(int argc, char *argv[]) {
    using namespace boost::program_options;

    options_description options_description("OPTIONS");
    variables_map options_map;
    try {
        options_description.add_options()
                ("help,H", "Get help messages.")
                ("name,N", value<std::string>()->required(), "package name. Required. [string]")
                ("classPrefix,P", value<std::string>()->default_value(""), "class prefix. If specified, the newly created class (such as Cocoa Touch Class) will automatically have the specified prefix added to its name. [string]")
                ("authorName,A", value<std::vector<std::string>>()->multitoken(), "author name. Used for copy right text of file header. [string]")
                ;

        store(parse_command_line(argc, argv, options_description), options_map);
    }  catch (const error &ex) {
        std::cerr << ex.what() << "\n";
        exit(1);
    }

    if (options_map.count("help")) {
        std::cout << "OVERVIEW: Swift Package Creator. " << std::endl;
        std::cout << options_description << std::endl;
        exit(1);
    }

    // check required arguments, except "--help" or "-H".
    try {
        notify(options_map);    // If this function not called explicitly, it will not throw an error if the required parameter is missing.
    } catch (const boost::wrapexcept<required_option> &ex) {
        std::cout << "Error: " << ex.what() << ".\n";
        exit(1);
    }

    ProgramOptions program_options;
    program_options.package_name = options_map["name"].as<std::string>();
    program_options.class_prefix = options_map["classPrefix"].as<std::string>();
    std::vector<std::string> raw_author_name = options_map["authorName"].as<std::vector<std::string>>();
    for (std::string const& item : raw_author_name) {
        if (!program_options.author_name.empty()) {
            program_options.author_name += " ";
        }
        program_options.author_name += item;
    }

#if DEBUG
    std::cout << "Help Document:" << std::endl;
    std::cout << options_description << std::endl;

    std::cout << "Program options from shell command:" << std::endl;
    std::cout << "package name: " << program_options.package_name << std::endl;
    std::cout << "class prefix: " << program_options.class_prefix << std::endl;
    std::cout << "copy right: " << program_options.author_name << std::endl;
#endif

    return program_options;
}