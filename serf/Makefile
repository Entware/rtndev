#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=serf
PKG_VERSION:=1.3.10
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@APACHE/$(PKG_NAME)
PKG_HASH:=be81ef08baa2516ecda76a77adf7def7bc3227eeb578b9a33b45f7b41dc064e6

PKG_BUILD_DEPENDS:=scons/host

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/devel/scons/scons.mk

define Package/libserf
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libopenssl +libaprutil +unixodbc
	TITLE:=High performance C-based HTTP client library
	URL:=https://serf.apache.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libserf/description
 The serf library is a high performance C-based HTTP client library built upon
 the Apache Portable Runtime (APR) library. It is permissively licensed under
 the Apache License, v2. Key features:
  multiplexed, asynchronous connections
  SSL/TLS support
  full HTTP pipelining
  multiple authentication modes (Basic, Digest, Kerberos/NTLM)
  zero-copy support for increased throughput
 Serf is the default client library of Apache Subversion and Apache OpenOffice 
endef

# Dirty trick to define PATH_MAX. It is needed by apr.h.
# PATH_MAX is defined in <linux/limits> and is the same for all feeds

SCONS_OPTIONS += \
	CC="STAGING_DIR=$(STAGING_DIR) $(TOOLCHAIN_DIR)/bin/$(TARGET_CC_NOCACHE)" \
	CPPFLAGS="$(TARGET_CFLAGS) $(TARGET_CPPFLAGS) -DPATH_MAX=4096" \
	LIBDIR="$(STAGING_DIR)/opt/lib" \
	LINKFLAGS="$(TARGET_LDFLAGS)" \
	PREFIX="/opt"

define Build/Prepare
	$(call Build/Prepare/Default)
	( cd $(PKG_BUILD_DIR); \
		$(SED) 's,@STAGING_DIR@,$(STAGING_DIR)/opt,g' SConstruct; \
	)
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR); $(SCONS_VARS) scons $(SCONS_OPTIONS); )
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include/serf-1
	$(CP) $(PKG_BUILD_DIR)/{serf_bucket_types,serf_bucket_util,serf}.h $(1)/opt/include/serf-1
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/libserf-1.{a,so*} $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/serf-1.pc $(1)/opt/lib/pkgconfig
	$(SED) 's,-\(L\|R\)$(STAGING_DIR)/opt/lib ,,g' $(1)/opt/lib/pkgconfig/serf-1.pc
endef

define Package/libserf/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/libserf-1.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libserf))
