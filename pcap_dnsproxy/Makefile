#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Partial taken from
# https://github.com/wongsyrone/openwrt-Pcap_DNSProxy/blob/master/Makefile

include $(TOPDIR)/rules.mk

PKG_NAME:=pcap_dnsproxy
PKG_VERSION:=0.4.9.13
PKG_REV:=70a40bb3fc7399cc31344c29b993e7e02da4503b
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/chengr28/Pcap_DNSProxy.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/pcap_dnsproxy
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libsodium +libpcap +libstdcpp +libevent2 +libevent2-core
	TITLE:=WinPcap and LibPcap based DNS server
	URL:=$(PKG_SOURCE_URL)
	SUBMENU:=IP Addresses and Names
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pcap_dnsproxy/description
 Pcap_DNSProxy is a local DNS server based on WinPcap and LibPcap
endef


CMAKE_OPTIONS += \
	-DPLATFORM_OPENWRT=ON \
	-DENABLE_LIBSODIUM=ON \
	-DENABLE_PCAP=ON \

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include

define Build/Prepare
	$(call Build/Prepare/Default)
	$(SED) 's,^\xEF\xBB\xBF,,g' $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/*
	$(SED) 's,\x0D,,g' $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/*
endef

define Package/pcap_dnsproxy/conffiles
/opt/etc/pcap-dnsproxy/Config.conf
/opt/etc/pcap-dnsproxy/Hosts.conf
/opt/etc/pcap-dnsproxy/IPFilter.conf
/opt/etc/pcap-dnsproxy/Routing.txt
/opt/etc/pcap-dnsproxy/WhiteList.txt
endef

define Package/pcap_dnsproxy/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) \
	    $(PKG_INSTALL_DIR)/opt/sbin/Pcap_DNSProxy $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/pcap-dnsproxy
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/Config.ini \
	    $(1)/opt/etc/pcap-dnsproxy/Config.conf
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/Hosts.ini \
	    $(1)/opt/etc/pcap-dnsproxy/Hosts.conf
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/IPFilter.ini \
	    $(1)/opt/etc/pcap-dnsproxy/IPFilter.conf
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/Routing.txt \
	    $(1)/opt/etc/pcap-dnsproxy/Routing.txt
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/Source/Auxiliary/ExampleConfig/WhiteList.txt \
	    $(1)/opt/etc/pcap-dnsproxy/WhiteList.txt
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S54pcap_dnsproxy $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,pcap_dnsproxy))
