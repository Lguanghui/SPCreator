// Copyright (c) 2023, Guanghui Liang. All Rights Reserved.
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
// Created by Guanghui Liang on 2023/12/2.
//

#include "error.h"
#include <iostream>

/**
 * @brief Function to exit the program if an error occurs.
 *
 * This function prints an error message to the console and exits the program with a non-zero exit code.
 *
 * @param errorMessage The error message to be displayed.
 */
void ExitWithError(const std::string& errorMessage) {
    std::cerr << "Error: " << errorMessage << std::endl;
    exit(1);
}