# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=trafficserver
PKG_VERSION:=9.2.4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/apache/trafficserver/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=8b1bc72f0e3220ef10cc3f911b2b473c46f2191fdeb36eaeffb55ca215cac96a

PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/trafficserver
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web Servers/Proxies
  TITLE:=Apache Traffic Server
  URL:=https://trafficserver.apache.org
  DEPENDS:=+libatomic +libcap +libcurl +liblzma +libmaxminddb +libncursesw
  DEPENDS+=+libopenssl +libpcre +libstdcpp +luajit +zlib @HAS_LUAJIT_ARCH
endef

define Package/trafficserver/description
  Apache Traffic Server™ is a fast, scalable and extensible HTTP/1.1
  and HTTP/2 compliant caching proxy server.
endef

define Package/trafficserver/conffiles
/opt/etc/trafficserver/cache.config
/opt/etc/trafficserver/hosting.config
/opt/etc/trafficserver/ip_allow.yaml
/opt/etc/trafficserver/logging.yaml
/opt/etc/trafficserver/parent.config
/opt/etc/trafficserver/plugin.config
/opt/etc/trafficserver/records.config
/opt/etc/trafficserver/remap.config
/opt/etc/trafficserver/sni.yaml
/opt/etc/trafficserver/socks.config
/opt/etc/trafficserver/splitdns.config
/opt/etc/trafficserver/ssl_multicert.config
/opt/etc/trafficserver/storage.config
/opt/etc/trafficserver/strategies.yaml
/opt/etc/trafficserver/volume.config
endef

TARGET_CFLAGS += -pthread
TARGET_LDFLAGS += -latomic -ldl

ifeq ($(CONFIG_aarch64),y)
TARGET_CFLAGS += -fsigned-char
endif

CONFIGURE_ARGS:=$(filter-out	\
	--libdir=%		\
	--libexecdir=%		\
	--sysconfdir=%		\
	, $(CONFIGURE_ARGS))

CONFIGURE_ARGS += \
	--libdir=/opt/lib/trafficserver \
	--libexecdir=/opt/lib/trafficserver/plugins \
	--sysconfdir=/opt/etc/trafficserver \
	\
	--disable-tests \
	--disable-unwind \
	--enable-experimental-plugins

ifeq ($(CONFIG_ARCH_64BIT),)
CONFIGURE_ARGS += \
	--enable-32bit-build
endif

CONFIGURE_VARS += \
	ac_cv_lib_mysqlclient_mysql_info=no

define PreCompile
	( cd $(PKG_BUILD_DIR)/src/tscore; \
		HOST_CXX_FOR_BUILD="$(HOSTCXX)" \
		CPPFLAGS_FOR_BUILD="$(HOST_CPPFLAGS)" \
		$(MAKE) CompileParseRules; \
	)
endef
Hooks/Compile/Pre += PreCompile

define Package/trafficserver/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/traffic_* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/trafficserver
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/trafficserver/* \
		$(1)/opt/etc/trafficserver
	$(INSTALL_DIR) $(1)/opt/lib/trafficserver
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/trafficserver/*.so* \
		$(1)/opt/lib/trafficserver
	$(INSTALL_DIR) $(1)/opt/lib/trafficserver/plugins
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/trafficserver/plugins/*.so* \
		$(1)/opt/lib/trafficserver/plugins
	install -d -m0777 $(1)/opt/var/log/trafficserver
	install -d -m0777 $(1)/opt/var/trafficserver
endef

$(eval $(call BuildPackage,trafficserver))
