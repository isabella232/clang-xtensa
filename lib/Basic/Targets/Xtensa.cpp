//===--- Xtensa.cpp - Implement Xtensa target feature support ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements Xtensa TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;
#if 0
const Builtin::Info XtensaTargetInfo::BuiltinInfo[] = {
#define BUILTIN(ID, TYPE, ATTRS) \
  { #ID, TYPE, ATTRS, nullptr, ALL_LANGUAGES, nullptr },
#define LIBBUILTIN(ID, TYPE, ATTRS, HEADER) \
  { #ID, TYPE, ATTRS, HEADER, ALL_LANGUAGES, nullptr },
#include "clang/Basic/BuiltinsXtensa.def"
};
#endif
void XtensaTargetInfo::getTargetDefines(const LangOptions &Opts,
                      MacroBuilder &Builder) const {
  Builder.defineMacro("__Xtensa__");
  Builder.defineMacro("__xtensa__");
  Builder.defineMacro("__XTENSA__");
  Builder.defineMacro("__XTENSA_WINDOWED_ABI__");
  Builder.defineMacro("__XTENSA_EL__");    
}
#if 0
ArrayRef<Builtin::Info> XtensaTargetInfo::getTargetBuiltins() const {
  return llvm::makeArrayRef(BuiltinInfo, clang::Xtensa::LastTSBuiltin -
                                             Builtin::FirstTSBuiltin);
}
#endif
