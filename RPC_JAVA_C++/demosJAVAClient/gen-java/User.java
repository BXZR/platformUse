/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked", "unused"})
@javax.annotation.Generated(value = "Autogenerated by Thrift Compiler (0.10.0)", date = "2017-07-04")
public class User implements org.apache.thrift.TBase<User, User._Fields>, java.io.Serializable, Cloneable, Comparable<User> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("User");

  private static final org.apache.thrift.protocol.TField UID_FIELD_DESC = new org.apache.thrift.protocol.TField("uid", org.apache.thrift.protocol.TType.STRING, (short)1);
  private static final org.apache.thrift.protocol.TField UNAME_FIELD_DESC = new org.apache.thrift.protocol.TField("uname", org.apache.thrift.protocol.TType.STRING, (short)2);
  private static final org.apache.thrift.protocol.TField USEX_FIELD_DESC = new org.apache.thrift.protocol.TField("usex", org.apache.thrift.protocol.TType.BOOL, (short)3);
  private static final org.apache.thrift.protocol.TField UAGE_FIELD_DESC = new org.apache.thrift.protocol.TField("uage", org.apache.thrift.protocol.TType.I16, (short)4);

  private static final org.apache.thrift.scheme.SchemeFactory STANDARD_SCHEME_FACTORY = new UserStandardSchemeFactory();
  private static final org.apache.thrift.scheme.SchemeFactory TUPLE_SCHEME_FACTORY = new UserTupleSchemeFactory();

  public java.lang.String uid; // required
  public java.lang.String uname; // required
  public boolean usex; // required
  public short uage; // required

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    UID((short)1, "uid"),
    UNAME((short)2, "uname"),
    USEX((short)3, "usex"),
    UAGE((short)4, "uage");

    private static final java.util.Map<java.lang.String, _Fields> byName = new java.util.HashMap<java.lang.String, _Fields>();

    static {
      for (_Fields field : java.util.EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // UID
          return UID;
        case 2: // UNAME
          return UNAME;
        case 3: // USEX
          return USEX;
        case 4: // UAGE
          return UAGE;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new java.lang.IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    public static _Fields findByName(java.lang.String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final java.lang.String _fieldName;

    _Fields(short thriftId, java.lang.String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public java.lang.String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  private static final int __USEX_ISSET_ID = 0;
  private static final int __UAGE_ISSET_ID = 1;
  private byte __isset_bitfield = 0;
  public static final java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    java.util.Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new java.util.EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.UID, new org.apache.thrift.meta_data.FieldMetaData("uid", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.UNAME, new org.apache.thrift.meta_data.FieldMetaData("uname", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.USEX, new org.apache.thrift.meta_data.FieldMetaData("usex", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.BOOL)));
    tmpMap.put(_Fields.UAGE, new org.apache.thrift.meta_data.FieldMetaData("uage", org.apache.thrift.TFieldRequirementType.DEFAULT, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I16)));
    metaDataMap = java.util.Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(User.class, metaDataMap);
  }

  public User() {
  }

  public User(
    java.lang.String uid,
    java.lang.String uname,
    boolean usex,
    short uage)
  {
    this();
    this.uid = uid;
    this.uname = uname;
    this.usex = usex;
    setUsexIsSet(true);
    this.uage = uage;
    setUageIsSet(true);
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public User(User other) {
    __isset_bitfield = other.__isset_bitfield;
    if (other.isSetUid()) {
      this.uid = other.uid;
    }
    if (other.isSetUname()) {
      this.uname = other.uname;
    }
    this.usex = other.usex;
    this.uage = other.uage;
  }

  public User deepCopy() {
    return new User(this);
  }

  @Override
  public void clear() {
    this.uid = null;
    this.uname = null;
    setUsexIsSet(false);
    this.usex = false;
    setUageIsSet(false);
    this.uage = 0;
  }

  public java.lang.String getUid() {
    return this.uid;
  }

  public User setUid(java.lang.String uid) {
    this.uid = uid;
    return this;
  }

  public void unsetUid() {
    this.uid = null;
  }

  /** Returns true if field uid is set (has been assigned a value) and false otherwise */
  public boolean isSetUid() {
    return this.uid != null;
  }

  public void setUidIsSet(boolean value) {
    if (!value) {
      this.uid = null;
    }
  }

  public java.lang.String getUname() {
    return this.uname;
  }

  public User setUname(java.lang.String uname) {
    this.uname = uname;
    return this;
  }

  public void unsetUname() {
    this.uname = null;
  }

  /** Returns true if field uname is set (has been assigned a value) and false otherwise */
  public boolean isSetUname() {
    return this.uname != null;
  }

  public void setUnameIsSet(boolean value) {
    if (!value) {
      this.uname = null;
    }
  }

  public boolean isUsex() {
    return this.usex;
  }

  public User setUsex(boolean usex) {
    this.usex = usex;
    setUsexIsSet(true);
    return this;
  }

  public void unsetUsex() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __USEX_ISSET_ID);
  }

  /** Returns true if field usex is set (has been assigned a value) and false otherwise */
  public boolean isSetUsex() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __USEX_ISSET_ID);
  }

  public void setUsexIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __USEX_ISSET_ID, value);
  }

  public short getUage() {
    return this.uage;
  }

  public User setUage(short uage) {
    this.uage = uage;
    setUageIsSet(true);
    return this;
  }

  public void unsetUage() {
    __isset_bitfield = org.apache.thrift.EncodingUtils.clearBit(__isset_bitfield, __UAGE_ISSET_ID);
  }

  /** Returns true if field uage is set (has been assigned a value) and false otherwise */
  public boolean isSetUage() {
    return org.apache.thrift.EncodingUtils.testBit(__isset_bitfield, __UAGE_ISSET_ID);
  }

  public void setUageIsSet(boolean value) {
    __isset_bitfield = org.apache.thrift.EncodingUtils.setBit(__isset_bitfield, __UAGE_ISSET_ID, value);
  }

  public void setFieldValue(_Fields field, java.lang.Object value) {
    switch (field) {
    case UID:
      if (value == null) {
        unsetUid();
      } else {
        setUid((java.lang.String)value);
      }
      break;

    case UNAME:
      if (value == null) {
        unsetUname();
      } else {
        setUname((java.lang.String)value);
      }
      break;

    case USEX:
      if (value == null) {
        unsetUsex();
      } else {
        setUsex((java.lang.Boolean)value);
      }
      break;

    case UAGE:
      if (value == null) {
        unsetUage();
      } else {
        setUage((java.lang.Short)value);
      }
      break;

    }
  }

  public java.lang.Object getFieldValue(_Fields field) {
    switch (field) {
    case UID:
      return getUid();

    case UNAME:
      return getUname();

    case USEX:
      return isUsex();

    case UAGE:
      return getUage();

    }
    throw new java.lang.IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new java.lang.IllegalArgumentException();
    }

    switch (field) {
    case UID:
      return isSetUid();
    case UNAME:
      return isSetUname();
    case USEX:
      return isSetUsex();
    case UAGE:
      return isSetUage();
    }
    throw new java.lang.IllegalStateException();
  }

  @Override
  public boolean equals(java.lang.Object that) {
    if (that == null)
      return false;
    if (that instanceof User)
      return this.equals((User)that);
    return false;
  }

  public boolean equals(User that) {
    if (that == null)
      return false;
    if (this == that)
      return true;

    boolean this_present_uid = true && this.isSetUid();
    boolean that_present_uid = true && that.isSetUid();
    if (this_present_uid || that_present_uid) {
      if (!(this_present_uid && that_present_uid))
        return false;
      if (!this.uid.equals(that.uid))
        return false;
    }

    boolean this_present_uname = true && this.isSetUname();
    boolean that_present_uname = true && that.isSetUname();
    if (this_present_uname || that_present_uname) {
      if (!(this_present_uname && that_present_uname))
        return false;
      if (!this.uname.equals(that.uname))
        return false;
    }

    boolean this_present_usex = true;
    boolean that_present_usex = true;
    if (this_present_usex || that_present_usex) {
      if (!(this_present_usex && that_present_usex))
        return false;
      if (this.usex != that.usex)
        return false;
    }

    boolean this_present_uage = true;
    boolean that_present_uage = true;
    if (this_present_uage || that_present_uage) {
      if (!(this_present_uage && that_present_uage))
        return false;
      if (this.uage != that.uage)
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    int hashCode = 1;

    hashCode = hashCode * 8191 + ((isSetUid()) ? 131071 : 524287);
    if (isSetUid())
      hashCode = hashCode * 8191 + uid.hashCode();

    hashCode = hashCode * 8191 + ((isSetUname()) ? 131071 : 524287);
    if (isSetUname())
      hashCode = hashCode * 8191 + uname.hashCode();

    hashCode = hashCode * 8191 + ((usex) ? 131071 : 524287);

    hashCode = hashCode * 8191 + uage;

    return hashCode;
  }

  @Override
  public int compareTo(User other) {
    if (!getClass().equals(other.getClass())) {
      return getClass().getName().compareTo(other.getClass().getName());
    }

    int lastComparison = 0;

    lastComparison = java.lang.Boolean.valueOf(isSetUid()).compareTo(other.isSetUid());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetUid()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.uid, other.uid);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetUname()).compareTo(other.isSetUname());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetUname()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.uname, other.uname);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetUsex()).compareTo(other.isSetUsex());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetUsex()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.usex, other.usex);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    lastComparison = java.lang.Boolean.valueOf(isSetUage()).compareTo(other.isSetUage());
    if (lastComparison != 0) {
      return lastComparison;
    }
    if (isSetUage()) {
      lastComparison = org.apache.thrift.TBaseHelper.compareTo(this.uage, other.uage);
      if (lastComparison != 0) {
        return lastComparison;
      }
    }
    return 0;
  }

  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    scheme(iprot).read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    scheme(oprot).write(oprot, this);
  }

  @Override
  public java.lang.String toString() {
    java.lang.StringBuilder sb = new java.lang.StringBuilder("User(");
    boolean first = true;

    sb.append("uid:");
    if (this.uid == null) {
      sb.append("null");
    } else {
      sb.append(this.uid);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("uname:");
    if (this.uname == null) {
      sb.append("null");
    } else {
      sb.append(this.uname);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("usex:");
    sb.append(this.usex);
    first = false;
    if (!first) sb.append(", ");
    sb.append("uage:");
    sb.append(this.uage);
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, java.lang.ClassNotFoundException {
    try {
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class UserStandardSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public UserStandardScheme getScheme() {
      return new UserStandardScheme();
    }
  }

  private static class UserStandardScheme extends org.apache.thrift.scheme.StandardScheme<User> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, User struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // UID
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.uid = iprot.readString();
              struct.setUidIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // UNAME
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.uname = iprot.readString();
              struct.setUnameIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // USEX
            if (schemeField.type == org.apache.thrift.protocol.TType.BOOL) {
              struct.usex = iprot.readBool();
              struct.setUsexIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // UAGE
            if (schemeField.type == org.apache.thrift.protocol.TType.I16) {
              struct.uage = iprot.readI16();
              struct.setUageIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, User struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      if (struct.uid != null) {
        oprot.writeFieldBegin(UID_FIELD_DESC);
        oprot.writeString(struct.uid);
        oprot.writeFieldEnd();
      }
      if (struct.uname != null) {
        oprot.writeFieldBegin(UNAME_FIELD_DESC);
        oprot.writeString(struct.uname);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(USEX_FIELD_DESC);
      oprot.writeBool(struct.usex);
      oprot.writeFieldEnd();
      oprot.writeFieldBegin(UAGE_FIELD_DESC);
      oprot.writeI16(struct.uage);
      oprot.writeFieldEnd();
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class UserTupleSchemeFactory implements org.apache.thrift.scheme.SchemeFactory {
    public UserTupleScheme getScheme() {
      return new UserTupleScheme();
    }
  }

  private static class UserTupleScheme extends org.apache.thrift.scheme.TupleScheme<User> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, User struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol oprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet optionals = new java.util.BitSet();
      if (struct.isSetUid()) {
        optionals.set(0);
      }
      if (struct.isSetUname()) {
        optionals.set(1);
      }
      if (struct.isSetUsex()) {
        optionals.set(2);
      }
      if (struct.isSetUage()) {
        optionals.set(3);
      }
      oprot.writeBitSet(optionals, 4);
      if (struct.isSetUid()) {
        oprot.writeString(struct.uid);
      }
      if (struct.isSetUname()) {
        oprot.writeString(struct.uname);
      }
      if (struct.isSetUsex()) {
        oprot.writeBool(struct.usex);
      }
      if (struct.isSetUage()) {
        oprot.writeI16(struct.uage);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, User struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TTupleProtocol iprot = (org.apache.thrift.protocol.TTupleProtocol) prot;
      java.util.BitSet incoming = iprot.readBitSet(4);
      if (incoming.get(0)) {
        struct.uid = iprot.readString();
        struct.setUidIsSet(true);
      }
      if (incoming.get(1)) {
        struct.uname = iprot.readString();
        struct.setUnameIsSet(true);
      }
      if (incoming.get(2)) {
        struct.usex = iprot.readBool();
        struct.setUsexIsSet(true);
      }
      if (incoming.get(3)) {
        struct.uage = iprot.readI16();
        struct.setUageIsSet(true);
      }
    }
  }

  private static <S extends org.apache.thrift.scheme.IScheme> S scheme(org.apache.thrift.protocol.TProtocol proto) {
    return (org.apache.thrift.scheme.StandardScheme.class.equals(proto.getScheme()) ? STANDARD_SCHEME_FACTORY : TUPLE_SCHEME_FACTORY).getScheme();
  }
}
