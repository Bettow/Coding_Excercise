package structure;

import java.math.BigInteger;
import java.util.LinkedHashMap;

public class LRU<K,V> extends LinkedHashMap<K, V> {
	private final int LRU_CAPACITY = 1024;
	private int capacity;
	LinkedHashMap<Integer, Integer> lru;
	BigInteger b
}
