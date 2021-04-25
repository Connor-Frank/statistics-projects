import matplotlib.pyplot as plt
import numpy as np

from corr_coeff import correlation_coefficient

x = np.array([8, 8, 8, 8, 8, 9, 10, 10, 10, 10, 10, 10, 14, 14, 14, 14, 15, 16, 16, 16,
              16, 16, 4, 5, 5, 6, 8, 10, 12, 14, 16, 18, 20, 6, 8, 10, 12, 14, 16, 18, 20])

y = np.array([92, 94, 96, 98, 100, 110, 110, 112, 114, 116, 118, 120, 152, 154, 156, 158, 161, 170, 172, 174,
              176, 178, 59, 68, 70, 82, 104, 125, 144, 162, 180, 199, 220, 80, 102, 123, 142, 160, 178, 197, 218])

PLOT_NAME = 'pi-day-bonus'

fig, axs = plt.subplots(1, 2, figsize=(10, 5))

fig.suptitle(PLOT_NAME)
fig.canvas.set_window_title(PLOT_NAME)

axs[0].set_title("main")
axs[0].scatter(x, y, color='#2472c8')
coef = np.polyfit(x, y, 1)
poly1d_fn = np.poly1d(coef)
axs[0].plot(x, poly1d_fn(x), color='#cd3131', linewidth=2)

correlation = correlation_coefficient(x, y)
print(f"correlation coefficient: {correlation}")
determination = correlation ** 2
print(f"coefficient of determination: {determination}")

axs[1].set_title("residual plot")
predicted = poly1d_fn(x)
residuals = y - predicted
axs[1].scatter(x, residuals, color='#2472c8')
axs[1].plot(x, x * 0, color='#000000')
axs[1].set_ylim([-8.5, 8.5])

fig.savefig(PLOT_NAME + '.png', dpi=250,
            bbox_inches="tight", pad_inches=0.25)


def quit_figure(event):
    """define what will close the figure"""
    if event.key == 'q':
        plt.close(event.canvas.figure)


print("\npress q inside plot to quit\n")
cid = plt.gcf().canvas.mpl_connect('key_press_event', quit_figure)

plt.show()
