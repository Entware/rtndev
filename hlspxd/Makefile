#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=hlspxd
PKG_VERSION:=2016-12
PKG_RELEASE:=2

include $(INCLUDE_DIR)/package.mk

define Package/hlspxd
	SECTION:=net
	CATEGORY:=Network
	TITLE:=hls proxy
	DEPENDS:=+libstdcpp
	URL:=http://hlspx.ocry.com
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/hlspxd/description
 hlspxd works as a proxy with a DLNA server (xupnpd as an example) — it
 transforms HLS (m3u8) playlists into http streams.
endef

define Build/Compile
	$(TARGET_CXX) $(TARGET_CFLAGS) $(TARGET_CPPFLAGS) $(TARGET_LDFLAGS) -fsigned-char -o $(PKG_BUILD_DIR)/hlspxd \
		$(PKG_BUILD_DIR)/hlspxd.cpp $(PKG_BUILD_DIR)/platform.cpp $(PKG_BUILD_DIR)/utils.cpp $(PKG_BUILD_DIR)/videoviewer.cpp
endef

define Package/hlspxd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/hlspxd $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S92hlspxd $(1)/opt/etc/init.d/S92hlspxd
endef

$(eval $(call BuildPackage,hlspxd))
