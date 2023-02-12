import os.path
import numpy as np

from scipy.special import softmax

from tvm.contrib.download import download_testdata

labels_url = "https://s3.amazonaws.com/onnx-model-zoo/synset.txt"
labels_path = download_testdata(labels_url, "synset.txt", module="data")

with open(labels_path, "r") as f:
    labels = [l.rstrip() for l in f]

output_file = "predictions.npz"

if os.path.exists(output_file):
    with np.load(output_file) as data:
        scores = softmax(data["output_0"])
        # squeeze去除数组中维度为1的部分
        scores = np.squeeze(scores)
        print(np.argsort(scores))
        # 从最后一个元素到第一个元素复制一遍，排出来是升序，通过此种方法变为降序
        ranks = np.argsort(scores)[::-1]

        for rank in ranks[0:5]:
            print("class='%s' with probability=%f" % (labels[rank], scores[rank]))