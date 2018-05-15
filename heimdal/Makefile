#
# Copyright (C) 2017-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# it`s needed for samba4x only

include $(TOPDIR)/rules.mk

PKG_NAME:=heimdal
PKG_VERSION:=1.5.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.h5l.org/dist/src/
#PKG_HASH:=3872d3adfe1e7fa6e0da3a9bae65507881d52e5d347ca2f07080faa123c5f4c7

PKG_INSTALL:=1

PKG_BUILD_DEPENDS:=heimdal/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/host-build.mk

HOST_CONFIGURE_ARGS += \
	--disable-shared \
	--enable-static \
	--without-openldap \
	--without-capng \
	--without-sqlite3 \
	--without-libintl \
	--without-openssl \
	--without-berkeley-db \
	--without-readline \
	--without-libedit \
	--without-hesiod \
	--without-x \
	--disable-heimdal-documentation

define Host/Compile
	$(MAKE) -C $(HOST_BUILD_DIR)/include $(HOST_MAKE_FLAGS)
	$(MAKE) -C $(HOST_BUILD_DIR)/lib/roken $(HOST_MAKE_FLAGS)
	$(MAKE) -C $(HOST_BUILD_DIR)/lib/vers $(HOST_MAKE_FLAGS)
	$(MAKE) -C $(HOST_BUILD_DIR)/lib/com_err $(HOST_MAKE_FLAGS)
	$(MAKE) -C $(HOST_BUILD_DIR)/lib/asn1 $(HOST_MAKE_FLAGS)
	$(MAKE) -C $(HOST_BUILD_DIR)/lib/libedit $(HOST_MAKE_FLAGS)
	$(MAKE) -C $(HOST_BUILD_DIR)/lib/sl $(HOST_MAKE_FLAGS)
endef

define Host/Install
	$(INSTALL_DIR) $(STAGING_DIR)/host/bin
	$(CP) $(HOST_BUILD_DIR)/lib/com_err/compile_et $(STAGING_DIR_HOST)/bin
	$(CP) $(HOST_BUILD_DIR)/lib/asn1/asn1_compile $(STAGING_DIR_HOST)/bin
	$(CP) $(HOST_BUILD_DIR)/lib/sl/slc $(STAGING_DIR_HOST)/bin
endef

CONFIGURE_ARGS += \
	--disable-pk-init \
	--disable-kx509 \
	--disable-sqlite-cache \
	--enable-pthread-support \
	--disable-afs-support \
	--disable-ndbm-db \
	--with-cross-tools=$(STAGING_DIR_HOST)/bin \
	--disable-heimdal-documentation \
	--enable-developer \
	--with-sqlite3=yes \
	--with-sqlite3-include=$(STAGING_DIR)/opt/include \
	--with-sqlite3-lib=$(STAGING_DIR)/opt/lib \
	--with-openssl=yes \
	--with-openssl-include=$(STAGING_DIR)/opt/include \
	--with-openssl-lib=$(STAGING_DIR)/opt/lib \
	--without-x \
	--disable-afs-support \
	--disable-ndbm-db \
	--disable-mmap

EXTRA_CFLAGS += \
	-Wno-deprecated-declarations \
	-Wno-unused-variable \
	-Wno-unused-function \
	-Wno-maybe-uninitialized \
	-Wno-return-type \
	-Wno-enum-compare

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) files/roken-h-process.pl $(PKG_BUILD_DIR)/cf
endef

define Build/Compile
endef


define Package/heimdal/Default
	SECTION:=network
	CATEGORY:=Network
	SUBMENU:=Kerberos
	TITLE:=Heimdal Kerberos 5
	URL:=http://www.h5l.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/heimdal-libs
  $(call Package/heimdal/Default)
  TITLE+= (Libraries)
  DEPENDS:=+libsqlite3 +libreadline +libncurses +libopenssl
endef

define Package/heimdal-server
  $(call Package/heimdal/Default)
  TITLE+= (Server)
  DEPENDS:=+heimdal-libs
endef

define Package/heimdal-client
  $(call Package/heimdal/Default)
  TITLE+= (Client)
  DEPENDS:=+heimdal-libs
endef

define Package/heimdal-libs/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
endef

define Package/heimdal-client/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/kdestroy $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/kinit $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/kcc $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/klist $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/kpasswd $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/su $(1)/opt/bin/ksu
endef

define Package/heimdal-server/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/kadmin $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/ktutil $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/kstash $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/kdc $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/kadmind $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/kpasswdd $(1)/opt/sbin
endef

#define Build/InstallDev
#	$(INSTALL_DIR) $(1)/opt/include/heimdal
#	$(CP) $(PKG_BUILD_DIR)/include/heimdal/heimdal.h $(TOOLCHAIN_DIR)/include/sys
#	$(CP) $(PKG_BUILD_DIR)/include/heimdal/libheimdal.h $(1)/opt/include/heimdal
#	$(INSTALL_DIR) $(1)/opt/lib/
#	$(CP) $(PKG_BUILD_DIR)/libheimdal/.libs/libheimdal.{a,so*} $(1)/opt/lib/
#endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,heimdal-libs))
$(eval $(call BuildPackage,heimdal-client))
$(eval $(call BuildPackage,heimdal-server))
