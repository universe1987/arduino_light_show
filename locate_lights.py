import cv2
import numpy as np
from sklearn.cluster import KMeans


def convert_to_grayscale(src_path, dst_path):
    img = cv2.imread(src_path, 0)
    cv2.imwrite(dst_path, img)


def highlight_marks(src_path, dst_path):
    img = cv2.imread(src_path)
    img_diff = img[:, :, 1] - img[:, :, 0]
    img_diff[img_diff > 200] = 0
    img_diff[img_diff > 32] = 255
    cv2.imwrite(dst_path, img_diff)


def locate_centers(src_path, n_lights):
    img = cv2.imread(src_path, 0)
    y, x = np.where(img == 255)
    y = y.astype(float) / img.shape[0]
    x = x.astype(float) / img.shape[1]
    km = KMeans(n_clusters=n_lights).fit(np.vstack([x, y]).T)
    centers = km.cluster_centers_
    centers -= centers.mean(axis=0)
    max_r = np.sqrt(centers[:, 0] ** 2 + centers[:, 1] ** 2).max()
    centers /= max_r
    print(centers.min(), centers.max())
    return centers


if __name__ == '__main__':
    # highlight_marks('imgs/gray.jpg', 'imgs/marks.jpg')
    c = list(list(x) for x in locate_centers('imgs/marks.jpg', 60))
    print(sorted(c))
