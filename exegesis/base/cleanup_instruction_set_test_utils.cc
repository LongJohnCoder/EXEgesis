// Copyright 2016 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "exegesis/base/cleanup_instruction_set_test_utils.h"

#include "exegesis/proto/instructions.pb.h"
#include "exegesis/testing/test_util.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "src/google/protobuf/text_format.h"

namespace exegesis {

using testing::EqualsProto;

void TestTransform(const InstructionSetTransform& transform,
                   const string& input_proto, const string& expected_output) {
  InstructionSetProto instruction_set;
  ASSERT_TRUE(::google::protobuf::TextFormat::ParseFromString(
      input_proto, &instruction_set));
  ASSERT_OK(transform(&instruction_set));
  EXPECT_THAT(instruction_set, EqualsProto(expected_output));
}

}  // namespace exegesis
