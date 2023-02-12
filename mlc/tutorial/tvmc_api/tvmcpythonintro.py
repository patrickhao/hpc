from tvm.driver import tvmc

# 所有工作的起点，将其他框架表示的模型加载为TVM的上层图表示语言Relay
model = tvmc.load("my_model.onnx")

package = tvmc.compile(model, target="llvm")

result = tvmc.run(package, device="cpu")

print(result)