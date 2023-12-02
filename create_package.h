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

#ifndef SPCREATOR_CREATE_PACKAGE_H
#define SPCREATOR_CREATE_PACKAGE_H

#include "options_parse.h"

/**
 * create a swift package using official `swift package` command.
 */
void CreatePackage(ProgramOptions &options);

#endif //SPCREATOR_CREATE_PACKAGE_H
