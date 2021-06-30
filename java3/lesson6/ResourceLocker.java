package lesson6;

public interface ResourceLocker extends AutoCloseable {
	@Override
	void close();
}
