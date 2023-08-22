package test;

public class TimeoutChecker {

	private long timebegin = 0;

	private long timeout = 0;

	public TimeoutChecker(long timeout) {
		super();
		this.timeout = timeout;
		this.timebegin = System.currentTimeMillis();

	}

	public long getLeftTime() {

		if (timeout == 0) {
			return 0;
		} else if (timeout < 0) {
			return timeout;
		} else {

			long timeDead = timebegin + timeout;
			long timeNow = System.currentTimeMillis();

			// time is up
			if (timeNow >= timeDead) {
				return -1;
			} else {
				return timeDead - timeNow;
			}

		}
	}

	public long getPassedTime() {

		return System.currentTimeMillis() - timebegin;
	}

	public void reset() {
		this.timebegin = System.currentTimeMillis();
	}

	public boolean timeIsUpNow() {

		if (timeout == 0) {
			return false;
		} else if (timeout < 0) {
			return true;
		} else {

			long timeDead = timebegin + timeout;
			long timeNow = System.currentTimeMillis();
			return timeNow >= timeDead;
		}
	}
}
