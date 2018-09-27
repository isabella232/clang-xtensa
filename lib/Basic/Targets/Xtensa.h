//===--- Xtensa.h - Declare Xtensa target feature support ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares Xtensa TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_XTENSA_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_XTENSA_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/Compiler.h"

#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

namespace clang {
namespace targets {

class LLVM_LIBRARY_VISIBILITY XtensaTargetInfo : public TargetInfo {
 // static const Builtin::Info BuiltinInfo[];

public:
  XtensaTargetInfo(const llvm::Triple &Triple, const TargetOptions &)
      : TargetInfo(Triple) {
    BigEndian = false;
    NoAsmVariants = true;
    LongLongAlign = 32;
    SuitableAlign = 32;
    DoubleAlign = LongDoubleAlign = 32;
    SizeType = UnsignedInt;
    PtrDiffType = SignedInt;
    IntPtrType = SignedInt;
    WCharType = UnsignedChar;
    WIntType = UnsignedInt;
    UseZeroLengthBitfieldAlignment = true;
    resetDataLayout("e-m:e-p:32:32-i1:8:32-i8:8:32-i16:16:32-i64:64"
                       "-f64:64-a:0:32-n32");
  }


  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;/* {
    Builder.defineMacro("__Xtensa__");
  }*/

  ArrayRef<Builtin::Info> getTargetBuiltins() const override {
//    return llvm::makeArrayRef(BuiltinInfo,
//                           clang::Xtensa::LastTSBuiltin-Builtin::FirstTSBuiltin);
    return None;
  }

  BuiltinVaListKind getBuiltinVaListKind() const override {
//    return TargetInfo::VoidPtrBuiltinVaList;
    return TargetInfo::XtensaABIBuiltinVaList;
  }

  const char *getClobbers() const override {
    return "";
  }

  ArrayRef<const char *> getGCCRegNames() const override {
    static const char * const GCCRegNames[] = {
      "a0",   "sp",   "a1",   "a2",   "a3",   "a4",   "a5",   "a6", "a7",
      "a8",   "a9",   "a10",  "a11",  "a12",  "a13",  "a14",  "a15" /* , "sar", */
    };
    return llvm::makeArrayRef(GCCRegNames);
  }
  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
    return None;
  }
  bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &Info) const override {
    return false;
  }
  int getEHDataRegisterNumber(unsigned RegNo) const override {
    // R0=ExceptionPointerRegister R1=ExceptionSelectorRegister
    return (RegNo < 2)? RegNo : -1;
  }

};
} // namespace targets
} // namespace clang
#endif // LLVM_CLANG_LIB_BASIC_TARGETS_XTENSA_H
