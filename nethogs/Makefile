#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nethogs
PKG_VERSION:=0.8.5
PKG_RELEASE:=1

PKG_SOURCE:=v$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/raboof/nethogs/archive
PKG_HASH:=6a9392726feca43228b3f0265379154946ef0544c2ca2cac59ec35a24f469dcc

include $(INCLUDE_DIR)/package.mk

PKG_UNPACK:=gzip -dc $(DL_DIR)/$(PKG_SOURCE) | $(TAR) -C $(BUILD_DIR) $(TAR_OPTIONS)

define Package/nethogs
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libncurses +libpcap +libstdcpp
	TITLE:=NetHogs is a small 'net top' tool
	URL:=https://github.com/raboof/nethogs
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nethogs/description
 NetHogs is a small 'net top' tool. Instead of breaking the traffic down per
 protocol or per subnet, like most tools do, it groups bandwidth by process.
 If there's suddenly a lot of network traffic, you can fire up NetHogs and
 immediately see which PID is causing this. This makes it easy  to indentify
 programs that have gone wild and are suddenly taking up your bandwidth.
endef

TARGET_CFLAGS += $(TARGET_CPPFLAGS) $(TARGET_LDFLAGS) -fPIC

define Package/nethogs/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/nethogs $(1)/opt/sbin
endef

$(eval $(call BuildPackage,nethogs))
