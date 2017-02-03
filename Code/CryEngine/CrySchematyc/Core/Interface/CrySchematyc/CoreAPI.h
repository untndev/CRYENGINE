// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

// Prerequisite headers.

#include <CryMath/Cry_Math.h>
#include <CrySystem/ISystem.h>
#include <CrySystem/XML/IXml.h>

// Core headers.

#include "../Schematyc/Action.h"
#include "../Schematyc/Component.h"
#include "../Schematyc/FundamentalTypes.h"
#include "../Schematyc/ICore.h"
#include "../Schematyc/IObject.h"
#include "../Schematyc/IObjectProperties.h"

#include "../Schematyc/Compiler/CompilerContext.h"
#include "../Schematyc/Compiler/ICompiler.h"
#include "../Schematyc/Compiler/IGraphNodeCompiler.h"

#include "../Schematyc/Editor/IQuickSearchOptions.h"

#include "../Schematyc/Env/EnvContext.h"
#include "../Schematyc/Env/EnvElementBase.h"
#include "../Schematyc/Env/EnvPackage.h"
#include "../Schematyc/Env/EnvUtils.h"
#include "../Schematyc/Env/IEnvContext.h"
#include "../Schematyc/Env/IEnvElement.h"
#include "../Schematyc/Env/IEnvPackage.h"
#include "../Schematyc/Env/IEnvRegistrar.h"
#include "../Schematyc/Env/IEnvRegistry.h"

#include "../Schematyc/Env/Elements/EnvAction.h"
#include "../Schematyc/Env/Elements/EnvClass.h"
#include "../Schematyc/Env/Elements/EnvComponent.h"
#include "../Schematyc/Env/Elements/EnvDataType.h"
#include "../Schematyc/Env/Elements/EnvFunction.h"
#include "../Schematyc/Env/Elements/EnvInterface.h"
#include "../Schematyc/Env/Elements/EnvModule.h"
#include "../Schematyc/Env/Elements/EnvSignal.h"
#include "../Schematyc/Env/Elements/IEnvAction.h"
#include "../Schematyc/Env/Elements/IEnvClass.h"
#include "../Schematyc/Env/Elements/IEnvComponent.h"
#include "../Schematyc/Env/Elements/IEnvDataType.h"
#include "../Schematyc/Env/Elements/IEnvFunction.h"
#include "../Schematyc/Env/Elements/IEnvInterface.h"
#include "../Schematyc/Env/Elements/IEnvModule.h"
#include "../Schematyc/Env/Elements/IEnvSignal.h"

#include "../Schematyc/Network/INetworkObject.h"
#include "../Schematyc/Network/INetworkSpawnParams.h"

#include "../Schematyc/Reflection/ActionDesc.h"
#include "../Schematyc/Reflection/ComponentDesc.h"
#include "../Schematyc/Reflection/FunctionDesc.h"
#include "../Schematyc/Reflection/ReflectionUtils.h"
#include "../Schematyc/Reflection/TypeDesc.h"
#include "../Schematyc/Reflection/TypeOperators.h"

#include "../Schematyc/Runtime/IRuntimeClass.h"
#include "../Schematyc/Runtime/IRuntimeRegistry.h"
#include "../Schematyc/Runtime/RuntimeGraph.h"
#include "../Schematyc/Runtime/RuntimeParamMap.h"
#include "../Schematyc/Runtime/RuntimeParams.h"

#include "../Schematyc/Script/IScript.h"
#include "../Schematyc/Script/IScriptElement.h"
#include "../Schematyc/Script/IScriptExtension.h"
#include "../Schematyc/Script/IScriptGraph.h"
#include "../Schematyc/Script/IScriptRegistry.h"
#include "../Schematyc/Script/IScriptView.h"
#include "../Schematyc/Script/ScriptDependencyEnumerator.h"
#include "../Schematyc/Script/ScriptUtils.h"

#include "../Schematyc/Script/Elements/IScriptActionInstance.h"
#include "../Schematyc/Script/Elements/IScriptBase.h"
#include "../Schematyc/Script/Elements/IScriptClass.h"
#include "../Schematyc/Script/Elements/IScriptComponentInstance.h"
#include "../Schematyc/Script/Elements/IScriptConstructor.h"
#include "../Schematyc/Script/Elements/IScriptEnum.h"
#include "../Schematyc/Script/Elements/IScriptFunction.h"
#include "../Schematyc/Script/Elements/IScriptInterface.h"
#include "../Schematyc/Script/Elements/IScriptInterfaceFunction.h"
#include "../Schematyc/Script/Elements/IScriptInterfaceImpl.h"
#include "../Schematyc/Script/Elements/IScriptInterfaceTask.h"
#include "../Schematyc/Script/Elements/IScriptModule.h"
#include "../Schematyc/Script/Elements/IScriptRoot.h"
#include "../Schematyc/Script/Elements/IScriptSignal.h"
#include "../Schematyc/Script/Elements/IScriptSignalReceiver.h"
#include "../Schematyc/Script/Elements/IScriptState.h"
#include "../Schematyc/Script/Elements/IScriptStateMachine.h"
#include "../Schematyc/Script/Elements/IScriptStruct.h"
#include "../Schematyc/Script/Elements/IScriptTimer.h"
#include "../Schematyc/Script/Elements/IScriptVariable.h"

#include "../Schematyc/SerializationUtils/ContainerSerializationUtils.h"
#include "../Schematyc/SerializationUtils/ISerializationContext.h"
#include "../Schematyc/SerializationUtils/IValidatorArchive.h"
#include "../Schematyc/SerializationUtils/MultiPassSerializer.h"
#include "../Schematyc/SerializationUtils/SerializationQuickSearch.h"
#include "../Schematyc/SerializationUtils/SerializationToString.h"
#include "../Schematyc/SerializationUtils/SerializationUtils.h"

#include "../Schematyc/Services/ILog.h"
#include "../Schematyc/Services/ILogRecorder.h"
#include "../Schematyc/Services/ISettingsManager.h"
#include "../Schematyc/Services/ITimerSystem.h"
#include "../Schematyc/Services/IUpdateScheduler.h"
#include "../Schematyc/Services/LogMetaData.h"
#include "../Schematyc/Services/LogStreamName.h"

#include "../Schematyc/Utils/Any.h"
#include "../Schematyc/Utils/AnyArray.h"
#include "../Schematyc/Utils/Array.h"
#include "../Schematyc/Utils/Assert.h"
#include "../Schematyc/Utils/CryLinkUtils.h"
#include "../Schematyc/Utils/Delegate.h"
#include "../Schematyc/Utils/EnumFlags.h"
#include "../Schematyc/Utils/GUID.h"
#include "../Schematyc/Utils/HybridArray.h"
#include "../Schematyc/Utils/IGUIDRemapper.h"
#include "../Schematyc/Utils/IInterfaceMap.h"
#include "../Schematyc/Utils/IString.h"
#include "../Schematyc/Utils/PreprocessorUtils.h"
#include "../Schematyc/Utils/RingBuffer.h"
#include "../Schematyc/Utils/Rotation.h"
#include "../Schematyc/Utils/ScopedConnection.h"
#include "../Schematyc/Utils/Scratchpad.h"
#include "../Schematyc/Utils/SharedString.h"
#include "../Schematyc/Utils/Signal.h"
#include "../Schematyc/Utils/StackString.h"
#include "../Schematyc/Utils/STLUtils.h"
#include "../Schematyc/Utils/StringHashWrapper.h"
#include "../Schematyc/Utils/StringUtils.h"
#include "../Schematyc/Utils/Transform.h"
#include "../Schematyc/Utils/TypeName.h"
#include "../Schematyc/Utils/TypeUtils.h"
#include "../Schematyc/Utils/UniqueId.h"
#include "../Schematyc/Utils/Validator.h"
