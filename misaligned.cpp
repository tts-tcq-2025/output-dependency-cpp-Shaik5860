
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

class ColorPair {
    int index;
    String majorColor;
    String minorColor;

    ColorPair(int index, String majorColor, String minorColor) {
        this.index = index;
        this.majorColor = majorColor;
        this.minorColor = minorColor;
    }
}

public class ColorCode {

    public static List<ColorPair> generateColorMap() {
        String[] majorColor = {"White", "Red", "Black", "Yellow", "Violet"};
        String[] minorColor = {"Blue", "Orange", "Green", "Brown", "Slate"};

        List<ColorPair> colorMap = new ArrayList<>();

        for (int i = 0; i < majorColor.length; i++) {
            for (int j = 0; j < minorColor.length; j++) {
                colorMap.add(new ColorPair(i * 5 + j, majorColor[i], minorColor[j]));
            }
        }
        return colorMap;
    }

    public static String formatColorMapEntry(int index, String major, String minor) {
        return index + " | " + major + " | " + minor;
    }

    public static int printColorMap(Consumer<String> outputFunc) {
        List<ColorPair> colorMap = generateColorMap();
        for (ColorPair pair : colorMap) {
            outputFunc.accept(formatColorMapEntry(pair.index, pair.majorColor, pair.minorColor));
        }
        return colorMap.size();
    }

    // For test capture
    static List<String> capturedLines = new ArrayList<>();

    public static void fakeOutputFunc(String line) {
        capturedLines.add(line);
    }

    public static void testPrintColorMap() {
        System.out.println("\nPrint color map test");
        capturedLines.clear();  // Reset before test
        int result = printColorMap(ColorCode::fakeOutputFunc);

        // Expected output generation
        List<String> expectedLines = new ArrayList<>();
        String[] majorColor = {"White", "Red", "Black", "Yellow", "Violet"};
        String[] minorColor = {"Blue", "Orange", "Green", "Brown", "Slate"};

        for (int i = 0; i < majorColor.length; i++) {
            for (int j = 0; j < minorColor.length; j++) {
                int index = i * 5 + j;
                expectedLines.add(index + " | " + majorColor[i] + " | " + minorColor[j]);
            }
        }

        assert result == 25 : "Expected 25 entries, got " + result;
        assert capturedLines.equals(expectedLines) : "Captured output doesn't match expected output";

        System.out.println("All is well (maybe!)");
    }

    public static void main(String[] args) {
        testPrintColorMap();
    }
}