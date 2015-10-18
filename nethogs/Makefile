#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nethogs
PKG_VERSION:=0.8.1-20140625
PKG_REV:=580c4120994e0e815b01a3141ed1af0bbe841357
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/raboof/nethogs
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/nethogs
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libncurses +libpcap +libstdcpp
	TITLE:=NetHogs is a small 'net top' tool
	URL:=http://nethogs.sourceforge.net/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/nethogs/description
 NetHogs is a small 'net top' tool. Instead of breaking the traffic down per protocol 
 or per subnet, like most tools do, it groups bandwidth by process. NetHogs does not rely
 on a special kernel module to be loaded. If there's suddenly a lot of network traffic, 
 you can fire up NetHogs and immediately see which PID is causing this. This makes it easy 
 to indentify programs that have gone wild and are suddenly taking up your bandwidth.
endef

TARGET_CFLAGS += $(TARGET_CPPFLAGS) $(TARGET_LDFLAGS)
MAKE_FLAGS += \
	CFLAGS="$(TARGET_CFLAGS)" \
	DESTDIR=/opt \

define Package/nethogs/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nethogs $(1)/opt/sbin/
endef

$(eval $(call BuildPackage,nethogs))
