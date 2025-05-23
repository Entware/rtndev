# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=ntopng
PKG_VERSION:=6.4
PKG_RELEASE:=1

#PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
#PKG_SOURCE_URL:=https://codeload.github.com/ntop/ntopng/tar.gz/refs/tags/$(PKG_VERSION)?
#PKG_HASH:=3eaff9f13566e349cada66d41191824a80288ea19ff4427a49a682386348931d

PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ntop/ntopng
PKG_MIRROR_HASH:=cbb05d976f1e563b96655f4d1e9a67d14ab878b7968fc0888ee488fa0eb17564

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-3.0-or-later
PKG_LICENSE_FILES:=COPYING LICENSE

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/ntopng
  SECTION:=net
  CATEGORY:=Network
  TITLE:=display top network users
  URL:=https://www.ntop.org/
  DEPENDS:=+glib2 +libatomic +libcap +libcurl +libexpat +libgcrypt
  DEPENDS+=+libgpg-error +libhiredis +libjson-c +liblua5.4 +libopenldap
  DEPENDS+=+libmariadb +libmaxminddb +libndpi +libnetsnmp +libpcap
  DEPENDS+=+libradcli +libsodium +libsqlite3 +libstdcpp +libwrap
  DEPENDS+=+libzmq-nc +libzstd +zlib
  EXTRA_DEPENDS:=redis-server, redis-cli
endef

define Package/ntopng/description
  Web-based Traffic and Security Network Traffic Monitoring.
endef

define Package/ntopng/conffiles
/opt/etc/ntopng/ntopng.conf
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR); ./autogen.sh; \
		./configure \
			$(CONFIGURE_ARGS) \
			ARCH="$(ARCH)" \
			CFLAGS="$(TARGET_CFLAGS)" \
			CXXFLAGS="$(TARGET_CXXFLAGS)" \
			CPPFLAGS="$(TARGET_CPPFLAGS)" \
			LDFLAGS="$(TARGET_LDFLAGS)" \
			my_cv_rw_locks_supported=no \
	)
	( cd $(PKG_BUILD_DIR)/third-party/rrdtool-1.4.8; \
		NROFF=/bin/true TROFF=/bin/true ./configure \
		$(CONFIGURE_ARGS) \
		--disable-libdbi \
		--disable-libwrap \
		--disable-rrdcgi \
		--disable-libtool-lock \
		--disable-nls \
		--disable-rpath \
		--disable-perl \
		--disable-ruby \
		--disable-lua \
		--disable-tcl \
		--disable-python \
		--disable-dependency-tracking \
		--disable-rrd_graph \
		CFLAGS="$(TARGET_CFLAGS)" \
		CPPFLAGS="$(TARGET_CPPFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)" \
	)
endef

define Build/Compile
	( cd $(PKG_BUILD_DIR)/third-party/rrdtool-1.4.8/src; \
		$(MAKE) $(PKG_JOBS) librrd_th.la; \
	)
endef

define Package/ntopng/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ntopng $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S72ntopng $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/etc/ntopng
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/packages/etc/ntopng/ntopng.conf \
		 $(1)/opt/etc/ntopng
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ntopng $(1)/opt/share
	$(INSTALL_DIR) $(1)/opt/var/lib/ntopng
endef

define Package/ntopng/postinst
#!/bin/sh

echo -e "\n\t*** Please do not forget to download GeoIP databases from either ***\n\n
	\thttps://maxmind.com or https://db-ip.com\n"
endef

$(eval $(call BuildPackage,ntopng))
