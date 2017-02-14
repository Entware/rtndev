#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=accel-ppp
PKG_VERSION:=1.11.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_MD5SUM:=d64f5cb26a5d3fbc09268215e29174e5

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/accel-ppp
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	DEPENDS:=+libopenssl +libpcre +libpthread +librt
	TITLE:=accel-ppp VPN server
	URL:=https://accel-ppp.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/accel-ppp/description
 The ACCEL-PPP is high performance PPTP/L2TP/PPPoE server for Linux. Userspace
 daemon has its own PPP implementation, so it does not uses pppd and one process
 (multi-threaded) manages all connections.
endef

CMAKE_OPTIONS += \
	-DBUILD_DRIVER=FALSE \
	-DCMAKE_INSTALL_PREFIX=/opt \
	-DCMAKE_BUILD_TYPE=Release \
	-DLOG_PGSQL=FALSE \
	-DSHAPER=FALSE \
	-DRADIUS=TRUE \
	-DNETSNMP=FALSE \
	-DLOG_FILE=FALSE \
	-DLIB_SUFFIX= \

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include \

TARGET_LDFLAGS += \
	-Wl,-rpath,/opt/lib/accel-ppp

define Package/accel-ppp/conffiles
/opt/etc/accel-ppp.conf
endef

define Build/InstallDev
	true
endef

define Package/accel-ppp/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/accel-cmd $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/accel-pppd $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/lib/accel-ppp
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/lib/accel-ppp/lib*.so \
		$(1)/opt/lib/accel-ppp
	$(INSTALL_DIR) $(1)/opt/share/accel-ppp/l2tp
	$(INSTALL_DATA) \
		$(PKG_INSTALL_DIR)/opt/share/accel-ppp/l2tp/dictionary* \
		$(1)/opt/share/accel-ppp/l2tp
	$(INSTALL_DIR) $(1)/opt/share/accel-ppp/radius
	$(INSTALL_DATA) \
		$(PKG_INSTALL_DIR)/opt/share/accel-ppp/radius/dictionary* \
		$(1)/opt/share/accel-ppp/radius
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/accel-pppd/accel-ppp.conf $(1)/opt/etc
	$(INSTALL_BIN) files/S60accel-ppp $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/log/accel-ppp
endef

$(eval $(call BuildPackage,accel-ppp))
