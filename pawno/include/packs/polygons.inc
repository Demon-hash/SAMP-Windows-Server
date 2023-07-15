#if defined _polygon_pack_included
	#endinput
#endif
#define _polygon_pack_included

#define RECTANGLE 4

enum POINT { Float: _ptX_, Float: _ptY_ };

stock Float:floatmin(Float:first, Float:second) {
	return floatcmp(first, second) <= 0 ? first : second;
}

stock Float:floatmax(Float:first, Float:second) {
	return floatcmp(first, second) >= 0 ? first : second;
}

stock Float:ToPolygonPoint(const Float:x, const Float:y) {
	new Float:p[POINT];
	p[_ptX_] = x;
	p[_ptY_] = y;
	return p;
}

stock bool:IsPointInPolygon(const Float:p[POINT], const Float:polygon[][POINT], const len = sizeof(polygon)) {
    new bool:isInside = false;
    
    new Float:minX = polygon[0][_ptX_], Float:maxX = polygon[0][_ptX_];
    new Float:minY = polygon[0][_ptY_], Float:maxY = polygon[0][_ptY_];

	for (new Float:q[POINT], n = 1; n < len; n++) {
        q = polygon[n];
        minX = floatmin(q[_ptX_], minX);
        maxX = floatmax(q[_ptX_], maxX);
        minY = floatmin(q[_ptY_], minY);
        maxY = floatmax(q[_ptY_], maxY);
    }

    if (p[_ptX_] < minX || p[_ptX_] > maxX || p[_ptY_] < minY || p[_ptY_] > maxY) {
        return false;
    }

    for (new i = 0, j = len - 1; i < len; j = i++) {
        if ((polygon[i][_ptY_] > p[_ptY_]) != (polygon[j][_ptY_] > p[_ptY_]) && p[_ptX_] < (polygon[j][_ptX_] - polygon[i][_ptX_]) * (p[_ptY_] - polygon[i][_ptY_]) / (polygon[j][_ptY_] - polygon[i][_ptY_]) + polygon[i][_ptX_]) {
            isInside = !isInside;
        }
    }

    return isInside;
}