/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// AEAD primitive (Authenticated Encryption with Associated Data, RFC 5116).
// TODO(przydatek): add documentation.

#ifndef TINK_PUBLIC_AEAD_H_
#define TINK_PUBLIC_AEAD_H_

#include "google/protobuf/stubs/stringpiece.h"
#include "google/protobuf/stubs/statusor.h"

namespace cloud {
namespace crypto {
namespace tink {

using google::protobuf::util::StatusOr;
using google::protobuf::StringPiece;

class Aead {
 public:
  virtual StatusOr<std::string> Encrypt(
     StringPiece plaintext, StringPiece associated_data) const = 0;
  virtual StatusOr<std::string> Decrypt(
     StringPiece ciphertext, StringPiece associated_data) const = 0;
  virtual ~Aead() {}
};

}  // namespace tink
}  // namespace crypto
}  // namespace cloud

#endif  // TINK_PUBLIC_AEAD_H_