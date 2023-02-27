// Returns the size of a static C-style array at compile time.
template <typename ElemTy, size_t Length>
consteval
size_t lengthof(ElemTy (&)[Length]) { return Length; }
